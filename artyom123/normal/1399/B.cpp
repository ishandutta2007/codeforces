#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int mna = INF, mnb = INF;
        for (auto &c : a) {
            cin >> c;
            mna = min(mna, c);
        }
        for (auto &c : b) {
            cin >> c;
            mnb = min(mnb, c);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(a[i] - mna, b[i] - mnb);
        }
        cout << ans << "\n";
    }
    return 0;
}