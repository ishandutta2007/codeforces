#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;

ll n, a[maxn], b[maxn], al[maxn], ar[maxn], bl[maxn], br[maxn], A[maxn], B[maxn], ans, cur;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = n - 1; i >= 0; i--) {
        A[i] = a[i] + (i != n - 1 ? A[i + 1] : 0);
        B[i] = b[i] + (i != n - 1 ? B[i + 1] : 0);
    }
    for(int i = n - 1; i >= 0; i--) {
        al[i] = (n - i) * a[i] + (i != n - 1 ? al[i + 1] : 0);
        bl[i] = (n - i) * b[i] + (i != n - 1 ? bl[i + 1] : 0);
        ar[i] = a[i] + (i != n - 1 ? ar[i + 1] + A[i + 1] : 0);
        br[i] = b[i] + (i != n - 1 ? br[i + 1] + B[i + 1] : 0);
    }
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            ll add = br[i] + al[i] + A[i] * (n - i) + (2 * i - 1) * (A[i] + B[i]);
            ans = max(ans, cur + add);
            cur += b[i] * (2 * i) + a[i] * (2 * i + 1);
        } else {
            ll add = ar[i] + bl[i] + B[i] * (n - i) + (2 * i - 1) * (A[i] + B[i]);
            ans = max(ans, cur + add);
            cur += a[i] * (2 * i) + b[i] * (2 * i + 1);
        }
    }
    cout << max(ans, cur);
}