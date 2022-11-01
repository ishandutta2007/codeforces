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
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;
const int base = 257;

int n, k, a[xn], ptr, sum[2], mx;
ll ans;
pii cnt[xn];

void add(int x, int id){
	if (cnt[x].B == id) ++ cnt[x].A;
	else cnt[x] = {1, id};
}
int get(int x, int id){
	if (cnt[x].B == id) return cnt[x].A;
	else return 0;
}

void build(int id, int l, int r){
	if (r - l == 1) return;
	int mid = l + r >> 1;
	ptr = mid;
	sum[0] = sum[1] = mx = 0;
	for (int i = mid; i < r; ++ i){
		sum[0] = (sum[0] + a[i]) % k;
		mx = max(mx, a[i]);
		while (ptr > l && a[ptr - 1] < mx){
			-- ptr;
			sum[1] = (sum[1] + a[ptr]) % k;
			add(sum[1] % k, id << 1);
		}
		ans += get((k - sum[0] + mx) % k, id << 1);
	}
	ptr = mid - 1;
	sum[0] = sum[1] = mx = 0;
	for (int i = mid - 1; i >= l; -- i){
		sum[0] = (sum[0] + a[i]) % k;
		mx = max(mx, a[i]);
		while (ptr < r - 1 && a[ptr + 1] <= mx){
			++ ptr;
			sum[1] = (sum[1] + a[ptr]) % k;
			add(sum[1] % k, id << 1 | 1);
		}
		ans += get((k - sum[0] + mx) % k, id << 1 | 1);
	}
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n + 1);
    cout << ans << endl;
	
    return 0;
}