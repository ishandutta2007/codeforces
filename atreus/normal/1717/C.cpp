#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int a[maxn], b[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    bool answer = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) 
            answer = false;
        if (a[i] < b[i] && b[i] > b[(i + 1) % n] + 1)
            answer = false;
    }
    cout << (answer ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}