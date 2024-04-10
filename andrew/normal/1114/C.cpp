#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define m_p make_pair
#define p_b push_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
const ll N = 2e5;
const ll MAXN = 1123456;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll f(ll n, ll k) {
	ll res = 0;
	while(n){
		n /= k;
		res += n;
	}
	return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, b;
    cin >> n >> b;

    ll ans = 1e18;

    ll m = n;

    while(b != 1){
        ll j = 0;
        bool fl = 0;
        for(j = 2; j * j <= b; j++)if(b % j == 0){
            fl = 1;
            break;
        }
        if(!fl)j = b;

        ll kol = 0;

        ll res = f(n, j);

        while(b % j == 0){
            kol++;
            b /= j;
        }
        ans = min(ans, res / kol);

    }

    cout << ans << "\n";

    return 0;
}