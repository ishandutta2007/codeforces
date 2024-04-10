#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
long long a[MAXN], pref[MAXN], suf[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    long long xx;
    cin >> n >> k >> xx;
    long long x = 1;
    for(int i = 0; i < k; i++)
        x *= xx;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    pref[0] = 0;
    for(int i = 0; i < n; i++)
        pref[i + 1] = (pref[i] | a[i]);
    suf[n] = 0;
    for(int i = n - 1; i >= 0; i--)
        suf[i] = (suf[i + 1] | a[i]);
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, (a[i] * x) | pref[i] | suf[i + 1]);
    cout << ans << '\n';
    return 0;
}