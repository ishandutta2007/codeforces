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
#include <limits>
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

int n, m;
char ans[100][101];

char minchar(int i, int j) {
    static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
    char cs[4]; int csn = 0;
    rep(d, 4) {
        int yy = i + dy[d], xx = j + dx[d];
        if(yy<0||yy>=n||xx<0||xx>=m) continue;
        cs[csn ++] = ans[yy][xx];
    }
    char a = 'A';
    while(find(cs, cs + csn, a) != cs + csn) ++ a;
    return a;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) rep(j, m) ans[i][j] = '?';
    set<pii> s;
    rep(i, n) rep(j, m) s.insert(mp(i, j));
    rep(i, n) rep(j, m) if(ans[i][j] == '?') {
        char a = minchar(i, j);
        int k;
        if(*s.begin() != mp(i, j)) cerr << "Error!" << endl;
        s.erase(mp(i, j));
        for(k = 2; ; k ++) {
            if(n < i + k) break;
            if(m < j + k) break;
            bool ok = true;
            rep(y, k) ok &= ans[i+y][j+(k-1)] == '?';
            rep(x, k) ok &= ans[i+(k-1)][j+x] == '?';
            if(!ok) break;
            rep(y, k) {
                if(0 < j) ok &= ans[i+y][j-1] != a;
                if(j+k < m) ok &= ans[i+y][j+k] != a;
            }
            rep(x, k) {
                if(0 < i) ok &= ans[i-1][j+x] != a;
                if(i+k < n) ok &= ans[i+k][j+x] != a;
            }
            if(!ok) break;

            set<pii>::iterator it = s.begin();
            if(it != s.end()) {
                char c = minchar(it->first, it->second);
                if(c < a) break;
            }

            rep(y, k)   s.erase(mp(i+y, j+k-1));
            rep(x, k-1) s.erase(mp(i+k-1, j+x));
        }
        -- k;
        rep(y, k) rep(x, k) ans[i+y][j+x] = a;
    }
    rep(i, n) {
        puts(ans[i]);
    }
    return 0;
}