#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        vector<int> odd;
        vector<int> even;
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            int u; cin >> u;
            if (u % 2) odd.pb(i);
            else even.pb(i);
        }
        if (odd.size() % 2) {
            odd.pop_back();
            even.pop_back(); 
        } else {
            if (odd.size() > 0) {
                odd.pop_back(); odd.pop_back();
            } else {
                even.pop_back(); even.pop_back();
            }
        }
        for (int i = 0; i < odd.size(); i+=2) cout << odd[i] << ' ' << odd[i + 1] << '\n';
        for (int i = 0; i < even.size(); i+=2) cout << even[i] << ' ' << even[i + 1] << '\n';
    }
    return 0;
}