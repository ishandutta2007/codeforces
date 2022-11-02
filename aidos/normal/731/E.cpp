#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
string s;
int n, k;
int a[maxn];
ll sum[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll mx = sum[n];
    ll last = mx;
    for(int i = n-1; i >= 1; i--) {
        ll cur = mx;
        last = cur;
        mx = max(sum[i] - cur, mx);
    }
    cout << last << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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