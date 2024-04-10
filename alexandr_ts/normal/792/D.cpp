#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 20;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    //string s;
    ll n, q;
    cin >> n >> q;
    fr(i1, q) {
        ll num;
        string s;
        cin >> num >> s;
        fr(i, s.size())
            if (s[i] == 'U') {
                if (2 * num == n + 1)
                    continue;
                for (ll j = 0; (1ll << j) <= n; j++)
                    if ((1ll << j) & num) {
                        if ((1ll << (j + 1)) & num)
                            num = num ^ (1ll << j);
                        else
                            num = num ^ (1ll << j) ^ (1ll << (j + 1ll));
                        break;
                    }
            }
            else if (s[i] == 'L') {
                if (num % 2)
                    continue;
                for (ll j = 0; (1ll << j) <= n; j++)
                    if ((1ll << j) & num) {
                        num = num ^ (1ll << j) ^ (1ll << (j - 1ll));
                        break;
                    }
            }
            else {
                if (num % 2)
                    continue;
                for (ll j = 0; (1ll << j) <= n; j++)
                    if ((1ll << j) & num) {
                        num = num ^ (1ll << (j - 1ll));
                        break;
                    }
            }
        cout << num << endl;
    }
}