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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1 << 30);
const int maxn = 1 << 18;

using namespace std;


ll d[2100][2100];
vector < pair < ll, pii > > S;
ll a[2100][2100];
int b[2100];
bool used[2100];
int n;
int get(int x){
    if( b[x] == x) return x;
    return b[x] = get(b[x]);
}
vector < pll > g[2100];
void dfs( int x, int p = -1, ll cost = -1){
    
    for(int i = 0; i < n; i++) 
        if( used[i] ) {
            a[x][i] = a[p][i] + cost;
            a[i][x] = a[p][i] + cost;
        }
    used[x]  = 1;
    
    for(int i = 0; i < g[x].size(); i++){
        if( !used[g[x][i].f]) dfs(g[x][i].f, x, g[x][i].s);
    }
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    ll maxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%I64d", &d[i][j]); 
            S.pb( mp(d[i][j], mp(i, j)));
        }
    }
    for(int i =0; i < n; i++) b[i] = i;
    sort(S.begin(), S.end());
    for(int i = 0; i < S.size(); i++){
        ll dd = S[i].f;
        int x = S[i].s.f;
        int y = S[i].s.s;
        if( get(x) != get(y)){
            if (dd == 0){
                cout << "NO\n";
                return 0;
            }
            g[x].pb(mp(y, dd));
            g[y].pb(mp(x, dd));
            b[get(x)] = get(y);
        }
    }
    dfs(0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if( a[i][j] != d[i][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }

    
    

    cout << "YES\n";






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}