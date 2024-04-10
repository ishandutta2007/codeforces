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
        int n;
        cin >> n;
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[x] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == n)
                cout << 1 << ' ';
            else
                cout << a[i] + 1 << ' ';
        }
        cout << '\n';
    }
}