#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
 
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 998244353;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    int i = m - 1, ind = -1;
    long long ans = 1;
    for (int j = n - 1; j >= 0; j--) {
        if (a[j] < b[i]) {
            if (ind == -1) {
                cout << 0;
                return 0;
            }
            if (i == 0) {
                cout << 0;
                return 0;
            }
            if (a[j] < b[i - 1]) {
                cout << 0;
                return 0;
            }
            ans *= (ind - j);
            ind = -1;
            ans %= mod;
            i--;
            if (a[j] == b[i]) ind = j;
            continue;
        }
        if (a[j] == b[i]) {
            ind = max(ind, j);
            continue;
        }
    }
    if (i != 0 || ind == -1) {
        cout << 0;
        return 0;
    }
    cout << ans;
    return 0;
}