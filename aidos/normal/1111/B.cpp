#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

ll n, k, m;
int a[maxn];
void solve() {
    cin >> n >> k >> m;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll sum = 0;
    ld ans = 0;
    for(ll i = n-1; i >= 0; i--) {
        sum += a[i];
        if(i > m) continue;
        ans = max(ans, ld(sum + min(k * (n-i), m-i))/(n-i));
    }
    printf("%.12lf\n", (double) ans);
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