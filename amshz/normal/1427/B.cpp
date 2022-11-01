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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int qq, n, a[xn], k, ans, last[2][xn], ted;
bool mark[xn];
string s;

bool cmp(int i, int j){
	int x = last[0][i];
	int y = last[1][i];
	int z = last[0][j];
	int w = last[1][j];
	//if (x + y != z + w) return x + y < z + w;
	if (x + y <= n && z + w <= n){
		if (x + y != z + w) return x + y < z + w;
		return i < j;
	}
	if (x + y <= n) return true;
	if (z + w <= n) return false;
	if (x <= n && z <= n) return i < j;
	if (y <= n && w <= n) return i > j;
	if (x <= n) return x < w;
	return y < z;
}

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n >> k >> s;
		s = '.' + s;
		int ptr = - n - n;
		ted = 0;
		for (int i = 1; i <= n; ++ i){
			if (s[i] == 'W'){
				ptr = i;
				last[0][i] = inf / 2;
				++ ted;
				continue;
			}
			last[0][i] = i - ptr;
		}
		if (!ted && k){
			cout << k + k - 1 << endl;
			continue;
		}
		ptr = n + n + n + 1;
		for (int i = n; i >= 1; -- i){
			a[i] = i;
			if (s[i] == 'W'){
				ptr = i;
				last[1][i] = inf / 2;
				mark[i] = true;
				continue;
			}
			mark[i] = false;
			last[1][i] = ptr - i;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= k; ++ i){
			int ind = a[i];
			//cout << i << " : " << ind << endl;
			if (mark[ind])
				break;
			mark[ind] = true;
		}
		ans = 0;
		for (int i = 1; i <= n; ++ i){
			ans += mark[i];
			ans += (mark[i] && mark[i - 1]);
		}
		cout << ans << endl;
	}
	
    return 0;
}