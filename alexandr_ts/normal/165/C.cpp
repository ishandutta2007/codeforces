#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll k;
    cin >> k;
    string s;
    cin >> s;
    vector <ll> ones;

    ones.pb(-1);

    fr(i, (ll)s.size())
        if (s[i] == '1')
            ones.pb(i);

    ll ans = 0;
    ll curl = 1;

    if ((ll)ones.size() - 1 < k) {
        cout << 0;
        return 0;
    }

    ones.pb((ll)s.size());

    //fr(i, (int)ones.size())
     //   cout << ones[i] << " ";cout << endl;

    if (!k) {
        frab(i, 1, (int)ones.size())
            ans += (ones[i] - 1 - ones[i - 1]) * (ones[i] - ones[i - 1]) / 2;
        cout << ans;
        return 0;
    }

    frab(i, k, (ll)ones.size() - 1) {
        ans += (ones[curl] - ones[curl - 1]) * (ones[i + 1] - ones[i]);
        curl++;
    }
    cout << ans;

}