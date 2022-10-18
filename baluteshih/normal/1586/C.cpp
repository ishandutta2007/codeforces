#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

string mp[1000005];
int sum[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> mp[i];
        mp[i].insert(mp[i].begin(), '?');
    }
    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j)
            if (mp[j][i - 1] == 'X' && mp[j - 1][i] == 'X')
                ++sum[i];
        sum[i] += sum[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (sum[l] == sum[r])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}