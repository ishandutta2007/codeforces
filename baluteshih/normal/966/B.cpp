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

pii arr[300005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].X, arr[i].Y = i;
    sort(arr + 1, arr + n + 1, greater<pii>());
    
    auto solve = [&](int rv) {
        int lw = 1, idx = 0;
        for (; lw <= n; ++lw) {
            while (idx + 1 <= n && (ll)arr[idx + 1].X * lw >= x1)
                ++idx;
            if (idx >= lw)
                break;
        }
        if (lw > n) return;
        for (int i = 1, idx2 = 0; i <= n; ++i) {
            while (idx2 + 1 <= n && (ll)arr[idx2 + 1].X * i >= x2)
                ++idx2;
            if (idx2 >= idx && idx2 >= lw + i) {
                cout << "Yes\n";
                if (!rv) {
                    cout << lw << " " << i << "\n";
                    for (int j = 1; j <= lw; ++j)
                        cout << arr[j].Y << " \n"[j == lw];
                    for (int j = lw + 1; j <= lw + i; ++j)
                        cout << arr[j].Y << " \n"[j == lw + i];
                }
                else {
                    cout << i << " " << lw << "\n";
                    for (int j = lw + 1; j <= lw + i; ++j)
                        cout << arr[j].Y << " \n"[j == lw + i];
                    for (int j = 1; j <= lw; ++j)
                        cout << arr[j].Y << " \n"[j == lw];
                }
                exit(0);
            }
        }
    };

    solve(0);
    swap(x1, x2);
    solve(1);
    cout << "No\n";
}