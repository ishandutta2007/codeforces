#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int MAXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int last = (n + 3) / 4;
        for (int i = 0; i < n - last; i++) cout << 9;
        for (int i = 0; i < last; i++) cout << 8;
        cout << "\n";
    }
    return 0;
}