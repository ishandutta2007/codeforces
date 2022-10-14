#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double
#define ll long long
#define pll pair<long long, long long>

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    int n;
    cin >> n;
    int left = 1, right = n + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        cout << '?' << " " << mid - 1 << " " << n << endl;
        ll x;
        cin >> x;
        if (x == 0) right = mid;
        else left = mid;
    }
    int k = left;
    cout << '?' << " " << 1 << " " << k - 1 << endl;
    ll x;
    cin >> x;
    cout << '?' << " " << 1 << " " << k << endl;
    ll y;
    cin >> y;
    int d = y - x;
    int j = k - d;
    cout << '?' << " " << 1 << " " << j - 1 << endl;
    cin >> x;
    cout << '?' << " " << 1 << " " << j - 2 << endl;
    cin >> y;
    int i = j - 1 - (x - y);
    cout << '!' << " " << i << " " << j << " " << k << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}