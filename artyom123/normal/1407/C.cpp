#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> ans(n);
    int i = 0;
    for (int j = 1; j < n; j++) {
        cout << '?' << " " << i + 1 << " " << j + 1 << endl;
        int ans1; cin >> ans1;
        cout << '?' << " " << j + 1 << " " << i + 1 << endl;
        int ans2; cin >> ans2;
        if (ans1 > ans2) {
            ans[i] = ans1; i = j;
        } else {
            ans[j] = ans2;
        }
    }
    cout << '!' << " ";
    for (auto &c : ans) cout << (c > 0 ? c : n) << " ";
    cout << endl;
    return 0;
}