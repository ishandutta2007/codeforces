#include<bits/stdc++.h>

using namespace std;

int get(int b, int A) {
    int ans = A;
    for (int i = 20; i >= 0; --i) {
        int x = ((b>>i)&1), y = ((A>>i)&1);
        if (x >= y) {
            ans |= (x * (1 << i));
        } else {
            break;
        }
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int ans = b - a;
        for (int A = a; A < b; ++A) {
            ans = min(ans, A - a + get(b, A) - b + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}