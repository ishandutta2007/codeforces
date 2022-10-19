#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int p[200005];
int pos[200005];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int sum = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<int> v;
    for (int i = n - k + 1; i <= n; i++) {
        v.pb(pos[i]);
        sum += i;
    }
    sort(all(v));
    long long ans = 1;
    for (int i = 1; i < v.size(); i++) {
        ans = ans * (v[i] - v[i - 1]) % 998244353;
    }
    cout << sum << ' ' << ans;
    return 0;
}