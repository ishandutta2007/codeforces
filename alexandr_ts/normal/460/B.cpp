#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

vector <ll> ans;

ll digS(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll a, b, c, st, t;
    cin >> a >> b >> c;
    fr(i, 100) {
        ll x = i;
        bool er = false;
        fr(j, a - 1) {
            x *= i;
            //if (x < 0)
                //er = true;
        }
        //if (er)
           // continue;
        x = x * b + c;
        if (digS(x) == i && x > 0 && x < MAX)
            ans.pb(x);
    }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] << " ";
}