#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const int S = 3 * 3 * 3 + 3, T = (S + 4 + 3) / 4 * 4;
int nextst[S][3][3];

void calcnextst() {
    mset(nextst, -1);
    int cs[3];
    for(cs[0] = 0; cs[0] < 3; cs[0] ++)
    for(cs[1] = 0; cs[1] < 3; cs[1] ++)
    for(cs[2] = 0; cs[2] < 3; cs[2] ++) {
        rep(c, 3) {
            int s = cs[0] * 9 + cs[1] * 3 + cs[2];
            if(cs[0] == c)
                nextst[s][c][0] = 27 + cs[2];
            if(cs[1] == c)
                nextst[s][c][1] = -2;
            if(cs[2] == c)
                nextst[s][c][2] = 27 + cs[0];
        }
    }
    rep(cc, 3) {
        rep(c, 3) {
            int s = 27 + cc;
            if(cc == c)
                nextst[s][c][0] = -2;
        }
    }
}

template<typename T>
inline size_t &hash_combine(size_t &x, const T &y) {
    return x ^= hash<T>()(y) + 0x9e3779b9 + (x << 6) + (x >> 2);
}

struct StateHash {
    size_t operator()(const vector<char> &num) const {
        unsigned *p = (unsigned*)&num[0];
        size_t h = 0;
        rep(i, T / 4)
            hash_combine(h, p[i]);
        return h;
    }
};

double rec(vector<char> num, char topcnt, char top1, char top2, char top3);

inline double recnext(vector<char> num, char topst, char top1, char top2, char top3, char col) {
    double r = 1e99;
    if(topst == 4) {
        int s = top1 * 9 + top2 * 3 + top3;
        ++ num[s];
        amin(r, rec(num, 0, col, 0, 0));
        amin(r, rec(num, 1, 0, col, 0));
        -- num[s];
    }else if(topst == 0) {
        amin(r, rec(num, 2, top1, col, 0));
        amin(r, rec(num, 3, top1, 0, col));
    }else if(topst == 1) {
        amin(r, rec(num, 2, col, top2, 0));
    }else if(topst == 2) {
        amin(r, rec(num, 4, top1, top2, col));
    }else if(topst == 3) {
        amin(r, rec(num, 4, top1, col, top3));
    }
    return r;
}

unordered_map<vector<char>,double,StateHash> memo;

double rec(vector<char> num, char topst, char top1, char top2, char top3) {
    if(top1 < top3) swap(top1, top3);
    num[S] = topst, num[S+1] = top1, num[S+2] = top2, num[S+3] = top3;

    auto it = memo.find(num);
    if(it != memo.end()) {
        if(it->second == -1) cerr << "loop!!!!" << endl;
        return it->second;
    }

    double r = 0; double &rr = memo[num]; rr = -1;
    r = 0;

    int waitp = 1;
    rep(col, 3) {
        double x = 1e99;
        rep(i, S) if(num[i] > 0) rep(k, 3) {
            int j = nextst[i][col][k];
            if(j != -1) {
                -- num[i]; if(j != -2) ++ num[j];
                amin(x, 1 + recnext(num, topst, top1, top2, top3, col));
                ++ num[i]; if(j != -2) -- num[j];
            }
        }
        int p = col == 0 ? 1 : 2;
        if(x == 1e99) waitp += p;
        else r += x * p / 6;
    }
    if(waitp == 6) r = 0;
    else r = (r + waitp / 6.) / (1 - waitp / 6.);

    return rr = r;
}

int getci(char c) { return c == 'R' ? 0 : c == 'G' ? 1 : 2; }

int main() {
    calcnextst();
    vector<char> num(T, 0);
    int n;
    scanf("%d", &n);
    char topst = -1, top1 = -1, top2 = -1, top3 = -1;
    rep(i, n) {
        static char buf[4];
        scanf("%s", buf);
        if(getci(buf[0]) > getci(buf[2])) swap(buf[0], buf[2]);
        if(i == n-1) {
            topst = 4;
            top1 = getci(buf[0]);
            top2 = getci(buf[1]);
            top3 = getci(buf[2]);
        }else {
            int s;
            if(buf[0] == '.')
                s = 27 + getci(buf[2]);
            else
                s = getci(buf[0]) * 9 + getci(buf[1]) * 3 + getci(buf[2]);
            num[s] ++;
        }
    }
    memo.clear();
    double ans = rec(num, topst, top1, top2, top3);
    printf("%.10f\n", ans);
    return 0;
}