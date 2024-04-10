#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
ll n, k;
void solve() {
    cin >> n >> k;
    k--;
    while(k > 0) {
        ll cur = n;
        ll mi = 10;
        ll mx = 0;
        while(cur > 0) {
            mi = min(mi, cur % 10);
            mx = max(mx, cur % 10);
            cur /= 10;
        }
        if(mi == 0) break;
        n += mi * mx;
        k--;
    }
    cout << n << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}