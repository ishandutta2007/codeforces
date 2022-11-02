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
int a[1100][1100];
int n, k, d;
vector < pair < int, pii > > ans[1100];
void get(int dd, int cnt, int x){
    if( x<=1) return;
    if( dd == 0 ){
        if( x > 1){
            cout << -1 << endl;//" asd ";
            //cout << cnt<< " " << x << endl;
            exit(0);
        }
        return;
    }
    //cout << x << endl;
    int z = x/min(k, x);
    int y = x % min(k, x);
    int t = 0;
    int g = 1;

    while( g <= y ) {
        get(dd-1, cnt + t, z + y);
        ans[d-dd].pb(mp(g, mp(cnt+t, cnt + z + t + y - 1)));
        t += z+y;
        g++;
    }
    if( z == 0) return;
    while( g <= k) {
        get(dd-1, cnt + t, z);
        ans[d - dd].pb( mp(g, mp(cnt + t, cnt + z + t-1)));
        t += z;
        g++;
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k >> d;
    if( n==1){
        for(int i = 0; i < d; i++) printf("1\n");
        return 0;
    }
    if(k == 1){
        printf("-1");
        return 0;
    }
    memset(a, -1, sizeof(a));
    if( k >= n){
        for(int i = 1; i<=n; i++) printf("%d ", i);
        printf("\n");
        for(int j = 1; j < d; j++) {
            for(int i = 0; i < n; i++) printf("1 ");
            printf("\n");
        }
        return 0;
    }
    get(d, 1, n);

    for(int i = 0; i < d; i++){
        for(int j = 0; j < ans[i].size(); j++){
            
            int fr=ans[i][j].s.f-1, to = ans[i][j].s.s;
            int g = ans[i][j].f;
            //if( g == 3) {
                //cerr << i << " " << j<< " "<< fr << " "<< to << endl;
            //}
            while( fr < to ){
                a[i][fr] = g;
                fr++;
            }
        }
    } 
    for(int i = 0; i< d; i++){
        for(int j = 0; j < n; j++){
            if( a[i][j] == -1) printf("%d ", k);
            else printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}