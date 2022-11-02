#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;
int n;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    int col = 0;
    int ans =1;
    int a = 0;

    int ans2 =1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++)
            for(int k =1; k<=3; k++){
                if( i + j + k == 6) col++;
                a++;
            }
    }
    for(int i = 0; i < n; i++){
        ans2 = (ans2 * 1ll * col) % mod;
        ans = (ans* 1ll * a) % mod;
    }
    ans -= ans2;
    ans += mod;
    ans %= mod;
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}