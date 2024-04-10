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
	     MOD = 1e9+7;
 
ll q, T, n, num[MAX1], sum, x, flag, ans;
 
int main(){
	fast_io;
	cin >> q;
	while (q--){
		cin >> n >> T;
		sum = 0;
		for (int i = 1; i <= n; ++i){
			cin >> num[i];
			sum += num[i];
		}
		if (sum <= T){
			cout << 0 << endl;
			continue;
		}
		sum = 0;
		flag = 0;
		for (int i = 1; i <= n; ++i){
			sum += num[i];
			if (sum-num[i] > T && sum-num[flag] > T)	break;
			if (num[i] > num[flag])	flag = i;
		}
		cout << flag << endl;
	}
    return 0;
}
/*                        now or never                 */