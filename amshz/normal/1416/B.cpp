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
 
const int xn = 1e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll qq, n, a[xn], sum, s, x;

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			sum += a[i];
		}
		if (n == 1){
			cout << 0 << endl;
			continue;
		}
		if (sum % n){
			cout << - 1 << endl;
			continue;
		}
		s = sum / n;
		cout << n + n + n - 3 << endl;
		for (int i = 2; i <= n; ++ i){
			x = (i - a[i] % i) % i;
			cout << 1 << sep << i << sep << x << endl;
			a[1] -= x;
			a[i] += x;
			cout << i << sep << 1 << sep << a[i] / i << endl;
			a[1] += a[i];
			a[i] = 0;
		}
		for (int i = 2; i <= n; ++ i) cout << 1 << sep << i << sep << s << endl;
	}
	
    return 0;
}