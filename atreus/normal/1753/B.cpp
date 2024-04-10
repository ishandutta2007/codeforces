#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 10;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        a[y]++;
    }
    for (int i = 1; i < MAXN; i++) {
        a[i + 1] += a[i] / (i + 1);
        a[i] %= (i + 1);
    }
    for (int i = 1; i < x; i++)
        if (a[i] != 0) {
            cout << "No\n";
            return 0;
        }
    cout << "YES\n";
}