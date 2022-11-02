#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll n, k;
ll max_d;
void check(ll d) {
    if(d <= max_d) return;
    ll sum = n/d;
    if(sum >= k * (k + 1)/2) {
        max_d = d;
    }
}
void solve() {
    cin >> n >> k;
    if(k > maxn) {
        cout << -1 << "\n";
        return;
    }
    if(n < k * (k + 1)/2) {
        cout << -1 << "\n";
        return;
    }
    for(ll d = 1; d  * d <= n; d++) {
        if(n % d == 0) {
            check(d);
            check(n/d);
        }
    }
    for(int i = 1; i < k; i++) {
        cout << i * max_d << " ";
        n -= i * max_d;
    }
    cout << n << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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