#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)                  (a).begin(), (a).end()
#define sz(a)                   int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(v)                   sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)                memset(a, b, sizeof a)
#define pb                              push_back
#define X                               first
#define Y                               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define pow             __pow
#define max             __max

int n, max, reg;
int pow[1024], dmg[1024];

int main(){
        #ifdef LocalHost
        freopen("x.in", "r", stdin);
        freopen("x.out", "w", stdout);
        #endif
        cin >> n >> max >> reg;
        REP (i, n) cin >> pow[i] >> dmg[i];
        vector <pii> res;
        int now = -1, h = max;
        for (; ; ) {
                ++now;
                if (now == 10000) {
                        puts("NO");
                        return 0;
                }
                h = min(max, h + reg);
                if (h <= 0) break;
                int i = -1;
                REP (j, n) 
                        if (h * 100 <= pow[j] * max && (i < 0 || dmg[j] > dmg[i])) 
                                i = j;
                if (~i) {
                        res.pb(pii(now, i + 1));
                        reg -= dmg[i];
                        pow[i] = 0;
                }
        }
        puts("YES");
        cout << now << ' ' << sz(res) << endl;
        REP (i, sz(res)) cout << res[i].X << ' ' << res[i].Y << endl;
        return 0;
}