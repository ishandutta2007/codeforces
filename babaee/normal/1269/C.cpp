/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> d[MAXN];

void func(ll x, ll y) {
    for (auto it = d[x].begin(); it != d[x].end(); it++) {
        *it = y;
    }
}

bool ok[MAXN] = {false};

int main() {
    fast_io;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        d[i % k].push_back(c - '0');
    }

    string s2;
    for (int i = 0; i < n; i++) {
        s2.push_back(d[i % k].front() + '0');
    }

    if (s2 >= s) return cout << n << endl << s2 << endl, 0;

    for (int i = 0; i < k; i++) {
        bool can = true;
        bool can2 = false;
        ll x = d[i].front();
        for (ll e : d[i]) {
            if (e < x) {
                can2 = true;
                ok[i] = true;
            }

            if (!can2 && e > x) {
                can = false;
                break;
            }
        }

        if (can) {
            continue;
        }

        for (ll j = k - 1; j >= i; j--) {
            if (d[j].front() == 9) continue;
            d[j][0]++;

            for (ll v = j + 1; v < k; v++) {
                d[v][0] = 0;
            }
            break;
        }

        break;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += SZ(d[i]);
    }

    cout << ans << endl;

    bool b = true;
    while (b) {
        for (int i = 0; i < k; i++) {
            if (SZ(d[i]) == 0) {
                b = false;
                break;
            }

            cout << d[i].front();
            d[i].pop_back();
        }
    }

    return 0;
}