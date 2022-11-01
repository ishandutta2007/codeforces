#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll pw[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    vector <int> ans;
    pw[0] = 1;
    frab(i, 1, 11)
        pw[i] = pw[i - 1] * 5;

    int cur = 0;

    frab(i, 1, M) {
        int tmp = i;
        while (tmp % 5 == 0) {
            cur++;
            tmp /= 5;
        }
        if (cur == n)
            ans.pb(i);
    }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] << " ";

}