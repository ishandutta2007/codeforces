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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;

    ll ans = inf, need = 0;
    if( c >= y ){
        need = (c - y + 1) * b1;
        y = c + 1;
    }
    

//    cout << ans << endl;
    for(int i = 0; i < 5000; i++){
//        cout << ans << endl;
        for(int j = 0; j < 5050; j++){
                int y1 = y + i;
                int z1 = z + j;
                if( z1 >= b){
                    ans = min(ans,  j*1ll*c1);
                    //cout<< j << endl;
                    continue;
                }
                int ans1 = (x + b - z1 - 1)/(b - z1);
                int ans2 = (a + y1 - c - 1)/( y1 - c);
                if( ans1 > ans2){
                    ans = min(ans, i* 1ll * b1 + j *1ll* c1);
                    continue;
                }
                ans = min(ans, i * 1ll * b1 + j * 1ll * c1 + ((ans2) * (b - z1)+1 - x) * 1ll*a1);
        }
    }
    cout << ans + need << endl;





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}