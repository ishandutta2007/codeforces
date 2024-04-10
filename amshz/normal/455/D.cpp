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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 500;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e5;
const int BASE = 257;

int n, q, num[xn], cnt[sq][xn], last, flag;
deque <int> dq[sq];

void update(int l, int r){
	flag = 0;
	if (l / SQ != r / SQ){
		flag = 1;
		for (int i = l - l % SQ + SQ - 1; i < r; i += SQ){
			int x = dq[i / SQ].back();
			dq[i / SQ].pop_back();
			-- cnt[i / SQ][x];
			dq[i / SQ + 1].push_front(x);
			++ cnt[i / SQ + 1][x];
		}
	}
	int x = dq[r / SQ][r % SQ + flag];
	-- cnt[r / SQ][x];
	for (int i = r % SQ - 1 + flag; i >= 0; -- i) dq[r / SQ][i + 1] = dq[r / SQ][i];
	dq[r / SQ].pop_front();
	dq[l / SQ].push_back(x);
	for (int i = min(n, SQ) - 1; i > l % SQ; -- i) dq[l / SQ][i] = dq[l / SQ][i - 1];
	dq[l / SQ][l % SQ] = x;
	++ cnt[l / SQ][x];
}
int get(int l, int r, int k){
	int ans = 0;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r){
			ans += cnt[i / SQ][k];
			i += SQ;
		}
		else{
			ans += dq[i / SQ][i % SQ] == k;
			++ i;
		}
	}
	return ans;
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> num[i];
    for (int i = 0; i < n; ++ i){
		dq[i / SQ].push_back(num[i]);
		++ cnt[i / SQ][num[i]];
	}
    cin >> q;
    while (q --){
    	int t, l, r, k;
    	cin >> t >> l >> r;
    	l = (l + last - 1) % n + 1;
    	r = (r + last - 1) % n + 1;
    	if (r < l) swap(l, r);
    	if (t == 1) update(l - 1, r - 1);
    	else{
    		cin >> k;
    		k = (k + last - 1) % n + 1;
    		last = get(l - 1, r - 1, k);
    		cout << last << endl;
		}
	}
    
    return 0;
}