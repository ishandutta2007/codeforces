#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const ll INF = 2e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> cnt(10001);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    for (int i = 0; i < 10000; i++) {
        for (int j = i + 1; j <= 10000; j++) {
            if (__builtin_popcount(i ^ j) == k) ans += cnt[i] * cnt[j];
        }
    }
    for (int i = 0; i <= 10000; i++) {
        if (k == 0) {
            ans += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }
    cout << ans;
    return 0;
}