#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;


    int k = 0, ans = 0;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (i > k)
            ++ans;
        k = max(k, x);
    }
    cout << ans;
    return 0;
}