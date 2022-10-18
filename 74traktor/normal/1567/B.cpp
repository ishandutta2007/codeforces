#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int pref[maxn];

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    cin >> t;
    for (int i = 1; i < maxn; ++i) pref[i] = (pref[i - 1]^i);
    while (t--) {
        cin >> a >> b;
        int now = pref[a - 1];
        if (now == b) cout << a << '\n';
        else {
            int need = (b^now);
            if (need != a) cout << a + 1 << '\n';
            else cout << a + 2 << '\n';
        }
    }
    return 0;
}