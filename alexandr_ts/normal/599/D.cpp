#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int f[N], b[N], a[N];

bool cmp(pr a, pr b) {
    return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll x;
    vector <pr> ans;
    cin >> x;
    for (ll b = 1; b <= ((6 * x) / b - 1 + b * b) / (3 * (b + 1));b++) {
            if (6 * x % b == 0) {
                ll a = ((6 * x) / b - 1 + b * b) / (3 * (b + 1));
                //if (b == 3)
                  //  cout << ((6 * x) / b - 1 + b * b) << " " << (3 * (b + 1)) << endl;
                if (6 * x == b * (3 * a * b - b * b + 3 * a + 1)) {
                    if (a != b && b < a)
                        ans.pb(mp(a, b)), ans.pb(mp(b, a));
                    else if (a == b) ans.pb(mp(a, b));
                }
            }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;
}