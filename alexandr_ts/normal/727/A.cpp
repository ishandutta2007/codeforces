#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 10;
const ll INF = 2e5 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N][N], b[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    vector <int> ans;
    ans.pb(b);
    while (b > a) {
        if (b % 2) {
            if ((b - 1) % 10) {
                cout << "NO";
                return 0;
            }
            b = (b - 1) / 10;
            ans.pb(b);
        }
        else {
            b = b / 2;
            ans.pb(b);
        }
    }
    if (b != a)
        cout << "NO";
    else {
        cout << "YES" << endl;
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto t: ans)
            cout << t << " ";
    }
}