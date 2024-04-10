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

#define MAXN (int) (1e7)
using namespace std;


vector < pii > t[3];
vector < int > g[1111];
int x[1111];
int y[1111];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        t[y[i]-1].pb(mp(x[i], i));
    }
    for(int i = 0; i < 2; i++){
        sort(t[i].begin(), t[i].end());
        reverse(t[i].begin(), t[i].end());
    }
    int l = 0, r = 0, z = k;
    while( l < t[0].size() && r < t[1].size() && z>0 && l + r+z<n){
        if( t[0][l].f <= t[1][r].f){
            g[z-1].pb(t[0][l].s);
            g[z-1].pb(t[1][r].s);
            l++;
            r++;
            z--;
        }
        else {
            g[z-1].pb(t[0][l].s);
            l++;
            z--;
        }
    }
    while( z > 0 && r < t[1].size()){
        g[z-1].pb(t[1][r].s);
        r++;
        z--;
    }
    while( z > 0 && l < t[0].size()){
        g[z-1].pb(t[0][l].s);
        l++;
        z--;
    }
    


    if(z == 0){
        while( l < t[0].size()) {
            g[0].pb(t[0][l].s);
            l++;
        }
        while( r < t[1].size()) {
            g[0].pb(t[1][r].s);
            r++;
        }
    }
    double ans = 0;

    for(int i = 0; i < k; i++){
        int mini = inf;  
        int ok = 0;
        for(int j = 0; j < g[i].size(); j++){
            int to = g[i][j];
            mini = min(mini, x[to]);
            ans += x[to];
            ok |= (y[to] == 1);
        }
        if(ok) ans -= mini/2.0;
    }
    printf("%.1lf\n", ans);
    for(int i = 0; i < k; i++){
        cout << g[i].size() <<  " ";
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] + 1 << " ";
        }
        cout << endl;
    }
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}