#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

int a[N];

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b + 1) {
        cout << -1;
        return 0;
    }
    if  (2 * a + 2 < b) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    if (a - 1 == b) {
        ans.pb(0);
        a--;
    }
    fr(i, min(a, b))
        ans.pb(1), ans.pb(0);

    b -= min(a, b);
    if (b) ans.pb(1), b--;
    fr(i, ans.size()) {
        cout << ans[i];
        if (ans[i] == 1 && b) {
            cout << 1;
            b--;
        }
    }
}