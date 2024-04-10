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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;
 
int n, k, ans, p[xn], a[xn], ptr, cnt[xn];
vector <int> vec;
bool mark[xn];
bitset <xn> bs;
 
void DFS(int v){
	mark[v] = true;
	++ ptr;
	if (!mark[p[v]]) DFS(p[v]);
}
 
int main(){
    InTheNameOfGod;
    
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> p[i];
	for (int i = 1; i <= n; ++ i){
		if (mark[i]) continue;
		ptr = 0;
		DFS(i);
		vec.push_back(ptr);
		++ cnt[ptr];
	}
	bs[0] = 1;
	for (int i = 1; i <= n; ++ i){
		while (cnt[i] > 2){
			++ cnt[i + i];
			cnt[i] -= 2;
		}
		if (cnt[i]) bs |= (bs << i);
		if (cnt[i] > 1) bs |= (bs << i);
	}
	cout << k + !bs[k] << sep;
	ptr = 0;
	for (int x : vec){
		for (int j = 0; j < x / 2; ++ j) a[ptr ++] = 2;
		if (x % 2) a[ptr ++] = 1;
	}
	sort(a, a + n);
	reverse(a, a + n);
	ans = 0;
	for (int i = 0; i < k; ++ i) ans += a[i];
	cout << ans << endl;
 
    return 0;
}