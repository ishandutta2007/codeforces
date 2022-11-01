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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, qq, a[xn], d[xn];
vector <int> vec[xn], S;

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i)
			d[i] = 0;
		for (int i = 1; i <= m; ++ i){
			cin >> a[i];
			vec[i].clear();
			for (int j = 0; j < a[i]; ++ j){
				int x;
				cin >> x;
				vec[i].push_back(x);
				++ d[x];
			}
		}
		S.clear();
		for (int i = 1; i <= n; ++ i)
			if (d[i] > (m + 1) / 2)
				S.push_back(i);
		if (!SZ(S)){
			cout << "YES" << endl;
			for (int i = 1; i <= m; ++ i)
				cout << vec[i][0] << sep;
			cout << endl;
			continue;
		}
		if (SZ(S) == 1){
			int ted = 0;
			for (int i = 1; i <= m; ++ i){
				bool flag = false;
				for (int x : vec[i])
					flag |= (x != S[0]);
				ted += !flag;
			}
			if (ted > (m + 1) / 2)
				cout << "NO" << endl;
			else{
				cout << "YES" << endl;
				for (int i = 1; i <= m; ++ i){
					int last = S[0];
					for (int x : vec[i])
						if (x != S[0])
							last = x;
					cout << last << sep;
				}
				cout << endl;
			}
			continue;
		}
		int cnt[2] = {0, 0};
		cout << "YES" << endl;
		for (int i = 1; i <= m; ++ i){
			bool f[2] = {0, 0};
			for (int x : vec[i]){
				f[0] |= (x == S[0]);
				f[1] |= (x == S[1]);
			}
			if (f[0] && !f[1])
				++ cnt[0];
			if (f[1] && !f[0])
				++ cnt[1];
		}
		for (int i = 1; i <= m; ++ i){
			bool f[2] = {0, 0};
			for (int x : vec[i]){
				f[0] |= (x == S[0]);
				f[1] |= (x == S[1]);
			}
			if (f[0] && !f[1])
				cout << S[0] << sep;
			else if (f[1] && !f[0])
				cout << S[1] << sep;
			else if (!f[0] && !f[1])
				cout << vec[i][0] << sep;
			else{
				if (cnt[0] < cnt[1])
					cout << S[0] << sep, ++ cnt[0];
				else
					cout << S[1] << sep, ++ cnt[1];
			}
		}
		cout << endl;
	}

	return 0;
}