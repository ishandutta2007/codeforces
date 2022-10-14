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
    int n;
    cin >> n;
    vector<int> cnt(20);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 20; j++) {
            if (x & (1 << j)) cnt[j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll now = 0;
        for (int j = 0; j < 20; j++) {
            if (cnt[j]) {
                now += (1 << j);
                cnt[j]--;
            }
        }
        ans += now * now;
    }
    cout << ans;
    return 0;
}