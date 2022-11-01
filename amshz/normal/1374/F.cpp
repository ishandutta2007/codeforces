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
 
const int xn = 5e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int qq, n, inv;
pii a[xn], b[xn];
vector <int> ans;
bool flag;
bool CMP(pii x, pii y){
	if (x.A != y.A) return x.A < y.A;
	return x.B < y.B;
}
void shift(int ind){
	ans.push_back(ind + 1);
	swap(a[ind], a[ind + 1]);
	swap(a[ind], a[ind + 2]);
}
void solve(int ind, int index){
	if (index < 2) return;
	for (int i = 0; i <= index; ++ i){
		if (a[i].B == ind){
			ind = i;
			break;
		}
	}
	while (ind != index){
		if (!ind) shift(ind);
		else shift(ind - 1);
		++ ind;
	}
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 0; i < n; ++ i) cin >> a[i].A, a[i].B = i, b[i] = a[i];
    	inv = 0, flag = false;
    	for (int i = 1; i < n; ++ i) for (int j = 0; j < i; ++ j) inv += CMP(a[i], a[j]), flag |= a[i].A == a[j].A;
    	sort(b, b + n, CMP);
    	if (!flag && inv % 2){
    		cout << -1 << endl;
    		continue;
		}
		if (inv % 2){
			for (int i = 1; i < n; ++ i){
				if (b[i].A == b[i - 1].A){
					swap(b[i], b[i - 1]);
					break;
				}
			}
		}
		ans.clear();
		reverse(b, b + n);
		for (int i = 0; i < n; ++ i) solve(b[i].B, n - i - 1);
		cout << SZ(ans) << endl;
		for (int val : ans) cout << val << sep;
		cout << endl;
	}
	
    return 0;
}