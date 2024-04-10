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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], b[xn], qq, ptr;
set <int> st, ts;
vector <int> ans;

int fnd1(int ind){
	if (st.lower_bound(ind + 1) != st.end())
		return *st.lower_bound(ind + 1);
	return *st.begin();
}
int fnd2(int ind){
	if (ts.lower_bound(ind + 1) != ts.end())
		return *ts.lower_bound(ind + 1);
	return *ts.begin();
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		st.clear(), ts.clear();
		cin >> n;
		for (int i = 0; i < n; ++ i)
			cin >> a[i], st.insert(i);
		for (int i = 0; i < n; ++ i){
			b[i] = __gcd(a[i], a[(i + 1) % n]);
			if (b[i] == 1)
				ts.insert(i);
		}
		ptr = - 1;
		ans.clear();
		while (SZ(ts) && SZ(st)){
			int ind = fnd2(ptr);
			int ind2 = fnd1(ind);
			int ind3 = fnd1(ind2);
			ans.push_back(ind2);
			if (b[ind2] == 1)
				ts.erase(ind2);
			b[ind] = __gcd(a[ind], a[ind3]);
			ts.erase(ind);
			st.erase(ind2);
			if (b[ind] == 1)
				ts.insert(ind);
			ptr = ind;
		}
		cout << SZ(ans) << sep;
		for (int x : ans)
			cout << x + 1 << sep;
		cout << endl;
	}

	return 0;
}