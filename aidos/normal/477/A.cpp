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
const int mod = (int) 1e9 + 7;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int a, b;
    cin >> a >> b;
    ll ans = 0, d  = (a * 1ll * ( a + 1)/ 2) % mod;
    d = (d * 1ll * b) % mod;
    d = (d + a) % mod;
    
    for(int i = 1; i < b; i++){
        ans = (ans + d * 1ll * i) % mod;
    }
    int ans2 = 0;
    /*for(int i = 1; i <= a; i++){
        for(int j = 1; j < b; j++){
            int x = i * j * b + j;
            ans2+=x;
        }
    } */
    cout << ans;// << " " << ans2 << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}