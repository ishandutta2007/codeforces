#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef string          str;

#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAX1 = 1e5+7,
	     MOD = 998244353;

ll q, n, m;
string s, t;


int main(){
	fast_io;
	cin >> q;
	while (q--){
		cin >> n >> m;
		cout << n/m*m + min(n-n/m*m, m/2) << endl;
	}
    return 0;
}
/*                        now or never                 */