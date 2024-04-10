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

const ll MAX1 = 5e5+7,
	     MOD = 1e9+7;

ll n, x, ans;

int main(){
	fast_io;
	cin >> n;
	ans = -1e18;
	for (int i = 0; i < n; ++i){
		cin >> x;
		if (x < 0)	ans = max(ans, x);
		else if (sqrt(x) != int(sqrt(x)))	ans = max(ans, x);
	}
	cout << ans;
    return 0;
}
/*                     now or never                         */