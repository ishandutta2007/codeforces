#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, w, b;
ll fact[4040];
int c[4040][4040];
void solve() {
    cin >> n >> w >> b;
    fact[0] = 1;
    for(int i = 1; i < 4040; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    for(int i = 0; i < 4040; i++) {
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i-1][j]) % mod;
        }
        c[i][0] = c[i][i] = 1;
    }
    ll ans = 0;
    for(int x = 1; x < n; x++) {
        int y = n - x;
        for(int k = 2; k <= 2; k++) {
            ll cur = c[w-1][x-1] *1ll* c[x - 1][k-1] % mod;
            ll cur2 = 0;
            if(k > 1) {
                cur2 = (cur2 + c[b-1][y-1] *1ll* c[y-1][k-2]) % mod;
            }
            //cout << x << " " << k << " " << cur << " "<<cur2 << "\n";
            ans =(ans + cur * cur2) % mod;
        }
    }
    ans = (ans * fact[w]) % mod;
    ans = (ans * fact[b]) % mod;

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}