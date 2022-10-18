#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

string mp[45];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            mp[i] = string(n, '.');
        for (int i = 0; i < n; i += 2)
            if (k > 0)
                --k, mp[i][i] = 'R';
        if (k)
            cout << "-1\n";
        else
            for (int i = 0; i < n; ++i)
                cout << mp[i] << "\n";
    }
}