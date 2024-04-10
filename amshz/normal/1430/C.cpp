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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int qq, n;

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n;
		cout << 2 << endl;
		if (n == 2){
			cout << 1 << sep << 2 << endl;
			continue;
		}
		cout << n - 2 << sep << n << endl;
		cout << n - 1 << sep << n - 1 << endl;
		for (int i = n - 3; i >= 1; -- i)
			cout << i << sep << i + 2 << endl;
	}
	
    return 0;
}