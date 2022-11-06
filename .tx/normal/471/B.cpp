#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pii > a;
    foi(n) {
        int x;
        cin >> x;
        a.pb(mp(x, i));
    }
    sort(all(a));
    vector<bool> used(n);
    vector<int> ans[3];
    foj(3) {
        bool swapped = false;
        foi(n) {
            ans[j].pb(a[i].sc);
            if (!swapped && i > 0 && !used[i] && a[i].fs == a[i - 1].fs) {
                swap(a[i], a[i - 1]);
                used[i] = true;
                swapped = true;
            }
        }
        if (j < 2 && !swapped) {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << endl;
    string s;
    foj(3) {
        for (auto i : ans[j]) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}