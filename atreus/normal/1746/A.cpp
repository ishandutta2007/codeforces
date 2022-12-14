#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        bool answer = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            answer |= x;
        }
        cout << (answer ? "YES\n" : "NO\n");
    }
}