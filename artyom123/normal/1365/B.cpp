#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> b(n);
        for (auto &c : b) cin >> c;
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) f = false;
        }
        if (f) {
            cout << "Yes\n";
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        for (auto &c : b) {
            if (c == 0) cnt0++;
            else cnt1++;
        }
        if (cnt0 != 0 && cnt1 != 0) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
    return 0;
}