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

const ll N = 1e3 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

ll a[N], b[N];

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    fr(i, s.size())
        a[s[i] - 'A']++;
    sort(a, a + 26);
    fr(i, 26)
        b[i] = a[i];
    ll cur = 25;
    ll ans = 0;
    while (m > 0) {
        if (b[cur]) {
            ans += min(m + a[cur] - b[cur], a[cur]);
            m--;
            b[cur]--;
        }
        else
            cur--;
    }
    cout << ans;
}