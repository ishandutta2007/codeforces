# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, ll>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 77777 + 10;
const int xm = 4;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 777777777;
const int base = 257;

int n, m, seg[xm][xm][xn << 2], ans;
bool flag[xm][xm];

void merge(int id){
	for (int i = 1; i <= 3; ++ i){
		for (int j = 1; j <= 3; ++ j)
			seg[i][j][id] = 0;
	}
	for (int i1 = 1; i1 <= 3; ++ i1)
		for (int i2 = 1; i2 <= 3; ++ i2)
			for (int i3 = 1; i3 <= 3; ++ i3)
				for (int i4 = 1; i4 <= 3; ++ i4)
					if (flag[i2][i3])
						seg[i1][i4][id] = (seg[i1][i4][id] + ll(seg[i1][i2][id << 1]) * ll(seg[i3][i4][id << 1 | 1]) % mod) % mod;
}
void build(int id, int l, int r){
	if (r - l == 1){
		for (int i = 1; i <= 3; ++ i)
			seg[i][i][id] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	merge(id);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		for (int i = 1; i <= 3; ++ i)
			for (int j = 1; j <= 3; ++ j)
				seg[i][j][id] = 0;
		if (val)
			seg[val][val][id] = 1;
		else
			for (int i = 1; i <= 3; ++ i) seg[i][i][id] = 1;
		ans = 0;
		for (int i = 1; i <= 3; ++ i)
			for (int j = 1; j <= 3; ++ j)
				ans += seg[i][j][id];
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, val);
	else
		modify(id << 1 | 1, mid, r, pos, val);
	merge(id);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= 3; ++ i)
		for (int j = 1; j <= 3; ++ j)
			cin >> flag[i][j];
	build(1, 1, n + 1);
	while (m --){
		int x, y;
		cin >> x >> y;
		modify(1, 1, n + 1, x, y);
		ans = 0;
		for (int i = 1; i <= 3; ++ i)
			for (int j = 1; j <= 3; ++ j)
				ans = (ans + seg[i][j][1]) % mod;
		cout << ans << endl;
	}
	
	return 0;
}