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

#define MAXN (int) (1e7)
using namespace std;

int d[300100];
int a[300100];
vector < pair < int, pii > > v;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        v.pb( mp(w, mp(x, y)));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < m; ){
        int j = i;
        while( j < m && v[j].f == v[i].f) j++;
        set < int > S;
        int k = j-1;
        while( k >= i){
            a[v[k].s.s] = d[v[k].s.s];
            S.insert( v[k].s.s);
            k--;
        }
        while( i < j){
            int fr = v[i].s.f;
            int to = v[i].s.s;
            if( S.find(fr) == S.end()){
                d[to] = max(d[to], d[fr] + 1);
            }
            else {
                d[to] = max(d[to], a[fr]+1);
            }
            i++;
        }
    }
    int maxn = 0;
    for(int i = 1; i <= n; i++) maxn = max(d[i], maxn);
    cout << maxn << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}