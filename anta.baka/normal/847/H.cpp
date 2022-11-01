#include <bits/stdc++.h>

using namespace std;

#define int long long
#define last dkjdgkjg

int n, a[100000], P[100000], S[100000], last, ans = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000, PP[100000], SS[100000];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    PP[0] = a[0];
    last = a[0];
    for(int i = 1; i < n; i++) {
        P[i] = P[i - 1];
        if(a[i] > last) {
            last = a[i];
        } else {
            last++;
            P[i] += last - a[i];
        }
        PP[i] = last;
    }

    SS[n - 1] = a[n - 1];
    last = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        S[i] = S[i + 1];
        if(a[i] > last) {
            last = a[i];
        } else {
            last++;
            S[i] += last - a[i];
        }
        SS[i] = last;
    }
    for(int i = 0; i < n; i++)
        ans = min(ans, (i != 0 ? P[i - 1] : 0) + (i != n - 1 ? S[i + 1] : 0) + max(PP[i], SS[i]) - a[i]);
    cout << ans;
}