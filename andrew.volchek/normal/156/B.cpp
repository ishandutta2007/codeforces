#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;

pair<int,int> g[maxn];
int fo[maxn], ag[maxn];

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d\n", &n, &m);
    int fs = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        scanf("%c%d\n", &c, &x);
        x--;
        g[i] = mp(c == '+', x);
        if (c == '+') {
            fs++;
            fo[x]++;
        } else {
            ag[x]++;
        }
    }

    vector<int> can(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ag[i] + fs - fo[i] == n - m) {
            can[i] = 1;
            cnt++;
        }
    }

    assert(cnt > 0);

    for (int i = 0; i < n; i++) {
        if (g[i].fst) {
            if (can[g[i].snd] && cnt == 1) {
                printf("Truth\n");
            } else if (can[g[i].snd]) {
                printf("Not defined\n");
            } else {
                printf("Lie\n");
            }
        } else {
            if (can[g[i].snd] && cnt == 1) {
                printf("Lie\n");
            } else if (can[g[i].snd]) {
                printf("Not defined\n");
            } else {
                printf("Truth\n");
            }
        }
    }

    return 0;
}