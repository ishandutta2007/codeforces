#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 1;
const ld EPS = 1e-9;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

vector <int> ans;

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //ans.pb(b), ans.pb(a), ans.pb(d), ans.pb(c);

    if (k < n + 1 || n == 4) {
        cout << "-1";
        return 0;
    }

    frab(i, 1, n + 1)
        if (i != a && i != b && i != c && i != d)
            ans.pb(i);
    cout << a << " " << c << " ";
    fr(i, ans.size())
        cout << ans[i] << " ";
    cout << d << " " << b << endl;

    cout << c << " " << a << " ";
    fr(i, ans.size())
        cout << ans[i] << " ";
    cout << b << " " << d;
}