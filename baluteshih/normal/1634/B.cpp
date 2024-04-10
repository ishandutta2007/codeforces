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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, sum;
        ll y;
        cin >> n >> x >> y;
        sum = y & 1;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            sum ^= a & 1;
        }
        if ((sum ^ x) & 1)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
}