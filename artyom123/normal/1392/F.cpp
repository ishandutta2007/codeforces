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
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (auto &c : a) {
        cin >> c;
        sum += c;
    }
    for (int i = 0; i < n; i++) {
        cout << i + (sum - n * (n - 1) / 2) / n + (i < (sum - n * (n - 1) / 2) % n) << " ";
    }
    return 0;
}