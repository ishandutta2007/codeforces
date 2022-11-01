#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long       ll;
 
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAX1 = 4e5+7,
	     MOD = 1e9+7;
 
ll n, m, x, cnt[MAX1], ans;
vector <ll> num[MAX1];
 
int main(){
	fast_io;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		num[i].push_back(0);
		for (int j = 1; j <= m; ++j)	cin >> x, num[i].push_back(x);
	}
	for (int j = 1; j <= m; ++j){
		fill(cnt, cnt+n+1, 0);
		for (int i = 1; i <= n; ++i){
			if (num[i][j] > n*m) continue;
			if (j%m == num[i][j]%m){
				x = (num[i][j]-1)/m+1;
				// cout << x << sep;
				if (i >= x)	cnt[i-x]++;
				else	cnt[n+i-x]++;
			}
		}
		// cout << endl;
		ll flag = n;
		for (int i = 0; i < n; ++i)	flag = min(flag, n+i-cnt[i]);
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}
/*                 now or never                 */