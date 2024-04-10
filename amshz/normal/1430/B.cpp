# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll qq, n, k, a[xn], ans;

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n >> k;
		for (int i = 1; i <= n; ++ i) cin >> a[i];
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		ans = 0;
		for (int i = 1; i <= k + 1; ++ i) ans += a[i];
		cout << ans << endl;
	}
 
    return 0;
}