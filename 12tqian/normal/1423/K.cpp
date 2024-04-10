#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << endl;}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e18 + 1;
const ll mod = 1e9 + 7;

const ll mv = 1e6 + 1;

ll n = mv;

ll bit[mv];
ll prime[mv];

//BIT

ll query(ll i) {
  ll ret = 0;
  for (; i>0; i-=i&-i)
    ret += bit[i];
  return ret;
}

void update(ll i, ll val) {
  for (; i<=n; i+=i&-i)
    bit[i] += val;
}

void supdate(ll i, ll val) {
    update(i, val);
    update(i + 1, -val);
}

//inclusive
void rupdate(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //sieve

    f0r(i, mv) {
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for (ll i = 2; i < mv; i++) {
        if (prime[i] && i * i < mv) {
            for (ll j = i * i; j < mv; j+= i) {
                prime[j] = 0;
            }
        }
    }


    for (ll i = 2; i < mv; i++) {
        if (prime[i]) {
            ll nv = i * i;

            nv = min(nv, mv);

            rupdate(i, nv-1, 1);
        }


    }


    ll t; cin >> t;

    f0r(i, t) {
        ll a; cin >> a;

        cout << query(a) + 1 << '\n';;
    }




}