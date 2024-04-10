#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

int a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x;
    cin >> x;
    frab(i, 1, 10)
        cin >> a[i];
    vector <int> ans;
    for (int i = 9; i >= 1; i--)
        if (a[i] == *min_element(a + 1, a + 10)) {
            fr(j, x / a[i])
                ans.pb(i);
            x -= a[i] * (int)ans.size();
            break;
        }

    //cout << x << endl;

    fr(i, min((int)ans.size(), 100)) {
        for (int j = 9; j >= 1; j--)
            if (j > ans[i] && a[j] - a[ans[i]] <= x) {
                x -= a[j] - a[ans[i]];
                ans[i] = j;
                break;
            }
    }
    if (ans.size() == 0) {
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    fr(i, ans.size())
        cout << ans[i];

}