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
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[4], cnt[26], ptr[26], b[xn], fen[xn];
string S, T, abc = "ANTO", res;
ll sum, ans;
vector <int> vec[26];

void mofen(int pos){
	for (pos += 5; pos < xn; pos += pos & - pos)
		++ fen[pos];
}
int gefen(int pos){
	int ansf = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		ansf += fen[pos];
	return ansf;
}
ll check(){
	for (int i = 0; i < 26; ++ i)
		vec[i].clear(), ptr[i] = 0;
	for (int i = 0; i < SZ(res); ++ i)
		vec[res[i] - 'A'].push_back(i);
	for (int i = 0; i < SZ(S) + 10; ++ i)
		fen[i] = 0;
	sum = 0;
	for (int i = 0; i < SZ(S); ++ i){
		int ind = S[i] - 'A';
		b[i] = vec[ind][ptr[ind]];
		++ ptr[ind];
		sum += gefen(SZ(S) - 1) - gefen(b[i]);
		mofen(b[i]);
	}
	return sum;
}
void solve(int ptr){
	if (ptr == 4){
		res = "";
		for (int i = 0; i < 4; ++ i)
			for (int j = 0; j < cnt[abc[a[i]] - 'A']; ++ j)
				res += abc[a[i]];
		ll x = check();
		if (ans < x)
			ans = x, T = res;
	}
	for (int i = 0; i < 4; ++ i){
		bool flag = true;
		for (int j = 0; j < ptr; ++ j)
			flag &= bool(a[j] != i);
		if (flag)
			a[ptr] = i, solve(ptr + 1);
	}
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> S, ans = 0, T = S;
		for (int i = 0; i < 26; ++ i)
			cnt[i] = 0;
		for (char c : S)
			++ cnt[c - 'A'];
		solve(0);
		cout << T << endl;
	}

	return 0;
}