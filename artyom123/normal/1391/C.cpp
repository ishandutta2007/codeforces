#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans = 1, tmp = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
        ans %= mod;
        tmp *= 2;
        tmp %= mod;
    }
    cout << (ans - tmp + mod) % mod;
    return 0;
}