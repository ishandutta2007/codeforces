#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

int n, m, k;
ll f[maxn];
void solve() {
    cin >> n >> m;
    f[0] = f[1] = 2;
    for(int i = 2; i < maxn; i++) {
        f[i] = (f[i-1] + f[i-2]) % mod;
    }
    cout << (f[n] + f[m] - 2) % mod << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}