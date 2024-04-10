#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
long long s[maxn];
int b[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }
    sort(b, b + k);
    reverse(b, b + k);
    long long ans = 0;
    while(k > 0 && b[k-1] == 1) {
        ans += 2*a[n-1];
        n--;
        k--;
    }
    int st = 0;
    for(int i = 0; i < k; i++) {
        ans += a[st];
        st += b[i]-1;
    }
    for(int i = st; i < n; i++) {
        ans += a[i];
    }
    cout << ans << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}