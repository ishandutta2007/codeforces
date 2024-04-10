#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5;
int A[maxn], B[maxn];
map < pair < int, int >, int > cnt;
map < int, int > cnta, cntb;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b >> k;
        for (int i = 1; i <= k; ++i) cin >> A[i];
        for (int i = 1; i <= k; ++i) cin >> B[i];
        ll ans = 0;
        cnt.clear();
        cnta.clear();
        cntb.clear();
        for (int i = 1; i <= k; ++i) {
            cnt[{A[i], B[i]}]++;
            cnta[A[i]]++;
            cntb[B[i]]++;
        }
        for (int i = 1; i <= k; ++i) {
            ans += (ll)(k - cnta[A[i]] - cntb[B[i]] + cnt[{A[i], B[i]}]);
        }
        cout << ans / 2 << '\n';
    }
    return 0;
}