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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], mx;
vector <pii> ans;
deque <pii> q[3];
bool mark[xn];

int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = n; i >= 1; -- i){
		if (!a[i]) continue;
		if (a[i] == 1){
			ans.push_back({i, mx + 1});
			q[1].push_back({i, mx + 1});
			++ mx;
		}
		else if (a[i] == 2){
			if (!SZ(q[1])) kill(- 1);
			pii x = q[1].front();
			q[1].pop_front();
			ans.push_back({i, x.B});
			q[2].push_back({i, x.B});
		}
		else{
			ans.push_back({i, mx + 1});
			++ mx;
			if (!SZ(q[2])){
				if (!SZ(q[1])) kill(- 1);
				pii x = q[1].front();
				q[1].pop_front();
				ans.push_back({x.A, mx});
			}
			else{
				pii x = q[2].front();
				q[2].pop_front();
				ans.push_back({x.A, mx});
			}
			q[2].push_back({i, mx});
		}
	}
	cout << SZ(ans) << endl;
	for (pii x : ans)
		cout << n - x.B + 1 << sep << x.A << endl;

    return 0;
}