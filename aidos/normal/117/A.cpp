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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        if( a == b ){
            /*ll ans = 0;
            int cnt = 2 * m - 2;
            int x = c % cnt;
            if( x < a){
                c += a - x - 1;
            }
            else if( x <= m-1 + m - a){
                c += m - 1 + m - b - x;
            }
            else {
                c -= x;
                c+=cnt;
                c += b-1;
            }*/
            cout << c << endl;
        }
        else if( a > b ){
            ll ans = 0;
            int cnt = 2 * m - 2;
            int x = c % cnt;
            if( m - 1 + m - a >= x) {
                c -= x;
                c += m - 1 + m - b;
                cout << c << endl;
            }
            else {
                c -= x;
                c += cnt;
                c += m - 1 + m-b;
                cout << c << endl;
            }
        }
        else {
            ll ans = 0;
            int cnt = 2 * m - 2;
            int x = c % cnt;
            if( a > x) {
                c -= x;
                c += b-1;
                cout << c << endl;
            }
            else {
                c -= x;
                c += cnt;
                c += b-1;
                cout << c << endl;
            }
        }
    }

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}