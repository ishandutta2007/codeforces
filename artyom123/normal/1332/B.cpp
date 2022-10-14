#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector <int> d = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        vector <int> col(n);
        vector <int> usd;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d.size(); j++) {
                if (a[i] % d[j] == 0) {
                    col[i] = j;
                    usd.push_back(j);
                    break;
                }
            }
        }
        sort(all(usd));
        usd.resize(unique(all(usd)) - usd.begin());
        map<int, int> ma;
        for (int i = 0; i < usd.size(); i++) {
            ma[usd[i]] = i + 1;
        }
        cout << usd.size() << "\n";
        for (auto &c : col) {
            cout << ma[c] << " ";
        }
        cout << "\n";
    }
}