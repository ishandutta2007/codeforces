#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 2e5;
const int INF = 2e9;

ll a[N];
vector <ll> odd;

int main() {
    //freopen("a.in", "r", stdin);
    ll n, ans = 0;
    cin >> n;
    fr(i, n) {
        ll tmp;
        cin >> tmp;
        if (tmp % 2) odd.pb(tmp);
        else
            ans += tmp;
    }
    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    cout << ans + accumulate(odd.begin(), odd.begin() + odd.size() / 2 * 2, 0ll);
}