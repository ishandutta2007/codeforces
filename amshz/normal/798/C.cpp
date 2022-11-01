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

const ll MAX1 = 2e5+7,
	     MOD = 1e9+7;

ll n, num[MAX1], flag, cnt;

ll gcd(ll a, ll b){
	if (a < b)	swap(a, b);
	if (b == 0)	return a;
	return gcd(b, a%b);
}

int main(){
	fast_io;
	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> num[i];
	flag = num[0];
	for (int i = 0; i < n; ++i)	flag = gcd(flag, num[i]);
	if (flag > 1){
		cout << "YES\n";
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n-1; ++i){
		if (num[i]%2 == 1){
			if (num[i+1]%2 == 1)	cnt += 1;
			else	cnt += 2;
			num[i] = 2, num[i+1] = 2;
		}
	}
	if (num[n-1]%2 == 1)	cnt += 2;
	cout << "YES\n" << cnt;
    return 0;
}
/*                     now or never                         */