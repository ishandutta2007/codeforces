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

int ans[1005][1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, nw, state;
    cin >> n >> k, nw = 1, state = 1;
    for (int i = 2; i <= n; ++i) {
        if (nw * k < i) {
            ++state;
            nw *= k;
        }
        for (int j = 1; j <= nw; ++j)
            ans[i][j] = state;
        for (int j = 1; nw + j < i; ++j)
            ans[i][nw + j] = ans[i - nw][j];
    }
    cout << state << "\n";
    for (int i = n; i >= 1; --i)
        for (int j = i - 1; j >= 1; --j)
            cout << ans[i][j] << " ";
    cout << "\n";
}