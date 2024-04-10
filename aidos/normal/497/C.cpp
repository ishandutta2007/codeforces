#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, xx;
pair < pii, int > c[100100];
pair < pii, int > d[100100];
int x[400100];
vector < pii > v[400100];
map < int, int > m;
set < pii > S;
int ans[100100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    int sz = 0;
    for(int i = 0; i< n; i++){
        scanf("%d %d", &c[i].f.f, &c[i].f.s);
        c[i].s = i;
        x[sz++] = c[i].f.f;
        x[sz++] = c[i].f.s;
    }
    scanf("%d", &xx);
    for(int i = 0; i <xx; i++) {
        scanf("%d %d %d", &d[i].f.f, &d[i].f.s, &d[i].s);
        x[sz++] = d[i].f.f;
        x[sz++] = d[i].f.s;
    }
    sort(x, x + sz);
    sz = unique(x, x + sz) - x;
    for(int i = 0; i < sz; i++)
        m[x[i]] = i;
    int last = -1;
    for(int i = 0; i < xx; i++){
        v[m[d[i].f.f]].pb(mp(d[i].f.s, i));
    }

    sort(c, c + n);
    for(int i = 0; i < n; i++){
        int t = m[c[i].f.f];
        for(int j = last+1; j <= t; j++){
            forit(v[j]){
                S.insert(*it);
            }
        }
        set < pii > :: iterator it = S.lower_bound(mp(c[i].f.s, -1));
        if( it == S.end()){
            cout << "NO\n";
            return 0;
        }
        int x =it->s;
        d[x].s--;
        if( d[x].s == 0){
            S.erase(it);
        }
        ans[c[i].s] = x+1;
        last = t;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}