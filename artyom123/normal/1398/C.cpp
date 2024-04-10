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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<int, int> ma;
        ma[0] = 1;
        int sum = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';
            ans += ma[sum - i - 1];
            ma[sum - i - 1]++;
        }
        cout << ans << "\n";
    }
    return 0;
}