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

int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
        if( n == 0) {
            cout << "0 1\n0 " << m << "\n0 0\n0 " << m-1 << endl;
            return 0;
        }
        
        if( m == 0) {
            cout << "1 0\n" << n << " 0\n0 0\n" << n-1 << " 0"<< endl;
            return 0;
        }
        vector < pii > d;
        double ans = 0.0;

        d.pb( mp(0, 0));
        d.pb(mp(1, 0));
        d.pb(mp(0, 1));
        d.pb( mp(n, m));
        if( n==1 && m == 1){}
        else {
        d.pb(mp(n-1, m));
        d.pb(mp(n, m-1));
        }
        if( n> 1 && m > 1){
            d.pb(mp(0, m));
            d.pb(mp(n, 0));
        }
        sort(d.begin(), d.end());
        do{
            double dis = 0.0;
            for(int i = 1; i<4; i++){
                dis += sqrt( (d[i].f - d[i-1].f) * (d[i].f - d[i-1].f) + (d[i].s - d[i-1].s) * (d[i].s - d[i-1].s) * 1.0);
            }
            if( ans < dis) ans = dis;
        }
        while(next_permutation(d.begin(), d.end()));

        sort(d.begin(), d.end());
        do{
            double dis = 0.0;
            for(int i = 1; i<4; i++){
                dis += sqrt( (d[i].f - d[i-1].f) * (d[i].f - d[i-1].f) + (d[i].s - d[i-1].s) * (d[i].s - d[i-1].s) * 1.0);
            }
            if( fabs(ans-dis) < 1e-9) {
                for(int i = 0; i < 4; i++){
                    cout << d[i].f << " " << d[i].s << endl;
                }
                return 0;
            }
        }
        while(next_permutation(d.begin(), d.end()));
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}