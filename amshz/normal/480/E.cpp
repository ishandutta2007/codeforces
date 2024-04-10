//khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, q, a[xn][xn], ans;
pii b[xn], last[xn][xn];
string s[xn];  
deque <int> dq1, dq2; 
vector <int> vec;
 
void modify(int ind){
	for (int i = 1; i <= m; ++ i){
		last[ind][i].A = last[ind][i - 1].A;
		if (a[ind][i])
			last[ind][i].A = i;
	}
	last[ind][m + 1].B = m + 1;
	for(int i = m; i >= 1; -- i){
		last[ind][i].B = last[ind][i + 1].B;
		if (a[ind][i])
			last[ind][i].B = i;
	}
}
bool check(int ind, int x){
	dq1.clear(), dq2.clear();
	for (int i = 1; i <= n; ++ i){
		while (SZ(dq1) && last[dq1.back()][ind].A < last[i][ind].A)
			dq1.pop_back();
		while (SZ(dq2) && last[dq2.back()][ind].B > last[i][ind].B)
			dq2.pop_back();
		dq1.push_back(i), dq2.push_back(i);
		while (SZ(dq1) && dq1[0] + x <= i)
			dq1.pop_front();
		while (SZ(dq2) && dq2[0] + x <= i)
			dq2.pop_front();
		if (x <= i && last[dq2.front()][ind].B - last[dq1.front()][ind].A - 1 >= x)
			return true;
	}
	return false;
}
int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> s[i];
		for (int j = 1; j <= m; ++ j)
			a[i][j] = (s[i][j - 1] == 'X');
	}
	for (int i = 1; i <= q; ++ i)
		cin >> b[i].A >> b[i].B, a[b[i].A][b[i].B] = 1;
	for (int i = 1; i <= n; ++ i)
		modify(i);
	for (int i = 1; i <= m; ++ i)
		while (check(i, ans + 1))
			++ ans;
	vec.push_back(ans);
	for (int i = q; i >= 2; -- i){
		a[b[i].A][b[i].B] = 0;
		modify(b[i].A);
		while (check(b[i].B, ans + 1))
			++ ans;
		vec.push_back(ans);
	}
	reverse(all(vec));
	for (int x : vec)
		cout << x << endl;
	
	return 0;
}