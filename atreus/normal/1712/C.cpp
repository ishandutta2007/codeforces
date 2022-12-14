#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];

void solve() {
    int n;
    cin >> n;

    map<int,int> right;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        right[a[i]] = i;
    }

    int best = n;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] <= a[i + 1])
            best--;
        else
            break;
    }
    if (best == 1) {
        cout << 0 << '\n';
        return;
    }
    set<int> allValues;
    set<int> S;
    for (int i = 1; i <= n; i++) {
        allValues.insert(a[i]);
        S.insert(right[a[i]]);
        if (!S.empty() and *S.begin() == i)
            S.erase(S.begin());
        
        if (S.empty() and i + 1 >= best) {
            cout << allValues.size() << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}