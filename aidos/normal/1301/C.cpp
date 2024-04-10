#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

ll n, m;
void solve() {
    cin >> n >> m;
    ll N = n - m;
    ll all = n * (n + 1)/2;
    ll k = N/(m+1);
    ll bad = k * (k + 1)/2 * (m + 1) + (k + 1) * (N % (m+1));
    cout << all - bad << "\n";
}


int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}