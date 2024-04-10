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
 
const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], qq, sum;

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], sum += a[i];
		if (sum == 0){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = n; i >= 1; -- i){
			int ind = 1;
			for (int j = 2; j <= i; ++ j)
				if (a[j] != sum)
					ind = j;
			swap(a[i], a[ind]);
			sum -= a[i];
		}
		for (int i = 1; i <= n; ++ i)
			cout << a[i] << sep;
		cout << endl;
	}
	
    return 0;
}