#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    if ((n - 1) >= s / 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n - 1; i++) {
        cout << 1 << " ";
    }
    cout << s - (n - 1) << "\n";
    cout << s - n;
    return 0;
}