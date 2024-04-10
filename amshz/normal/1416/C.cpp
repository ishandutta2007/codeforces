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
 
const int xn = 3e5 + 10;
const int xm = 1e7 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll n, a[xn], sz[xm], cnt[xn], ptr = 1, ans, x, tot[xn];
pii bach[xm];

void add(ll val, ll id, ll bit){
	++ sz[id];
	if (bit == - 1) return;
	bool flag = (val & (1LL << bit)) > 0;
	if (!bach[id].A) bach[id].A = ++ ptr;
	if (!bach[id].B) bach[id].B = ++ ptr;
	if (!flag) cnt[bit] += sz[bach[id].B];
	else tot[bit] += sz[bach[id].A];
	if (!flag) add(val, bach[id].A, bit - 1);
	else add(val, bach[id].B, bit - 1);
}

int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		add(a[i], 1, 31);
	}
	for (ll i = 0; i < 32; ++ i){
		ans += min(cnt[i], tot[i]);
		if (cnt[i] <= tot[i]) continue;
		x += (1LL << i);
	}
	cout << ans << sep << x << endl;
 
    return 0;
}