#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;

bool IS_MULTITEST = 0;

int query(int i, int j) {
    cout << '?' << " " << i + 1 << " " << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int i = 0, j = 1;
    int x = query(i, j);
    for (int k = 2; k < n; k++) {
        int y = query(j, k);
        if (x > y) i = k, x = y;
        else if (x == y) j = k, x = query(i, k);
    }
    vector<int> ind;
    for (int k = 0; k < n; k++) {
        if (k != i && k != j) ind.pb(k);
    }
    vector<int> p(n);
    random_shuffle(all(ind));
    for (auto &k : ind) {
        int x = query(i, k), y = query(j, k);
        if (x == y) continue;
        if (x > y) i = j, j = -1;
        break;
    }
    for (int j = 0; j < n; j++) {
        if (i != j) p[j] = query(i, j);
    }
    cout << '!' << " ";
    for (auto &c : p) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (IS_MULTITEST) cin >> t;
    while (t--) solve();
    return 0;
}