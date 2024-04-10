#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int nbDiff = 0;
    for (int i = 0; i < n; ++i)
        nbDiff += a[i]!= 0;
    if (nbDiff % 2) {
        cout << -1 << '\n';
        return ;
    }

    vector<pair<int, int>> sol;
    for (int i =0; i < n;) {
        if (!a[i]) {
            sol.emplace_back(i, i);
            ++i;
            continue;
        }
        int j = i+1;
        while (j < n and !a[j])
            ++j;
        assert(j < n);
        int nb0 = j - i - 1;
        if (a[i] == a[j]) {
            if (nb0 % 2 == 0)
                sol.emplace_back(i, j);
            else {
                sol.emplace_back(i, j-2);
                sol.emplace_back(j-1, j);
            }    
        } else {
            sol.emplace_back(i, j-1);
            sol.emplace_back(j, j);
        }
        i = j+1;
    }
    cout << sol.size() << '\n';
    for (auto [l, r] : sol)
        cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}