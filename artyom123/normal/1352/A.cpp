#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        int k = 1;
        while (n > 0) {
            a.pb((n % 10) * k);
            n /= 10;
            k *= 10;
        }
        vector<int> ans;
        for (auto &c : a) {
            if (c != 0) ans.pb(c);
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}