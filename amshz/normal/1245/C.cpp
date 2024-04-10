#include <bits/stdc++.h>
using namespace std;
typedef long long           ll;
typedef long double         ld;
#define F                   first
#define S                   second

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

const int xn = 1e5+10;
const ll md = 1e9+7;
ll fib[xn];


int main(){
	string a;
	cin >> a;
	fib[1] = 1, fib[2] = 2;
	for (int i=3; i<=a.size(); i++) fib[i] = (fib[i-1]+fib[i-2]+md)%md;
	ll ans = 1;
	int t = 0;
	for (int i=0; i<a.size(); i++){
		if (a[i] == 'm' or a[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i=0; i<a.size(); i++){
		if (a[i] == 'u') t++;
		else{
			if (t != 0) ans = (ans*fib[t]+md)%md;
			t = 0;
		}
	}
	if (t != 0) ans = (ans*fib[t]+md)%md;
	t = 0;
	for (int i=0; i<a.size(); i++){
		if (a[i] == 'n') t++;
		else{
			if (t != 0) ans = (ans*fib[t]+md)%md;
			t = 0;
		}
	}
	if (t != 0) ans = (ans*fib[t]+md)%md;
	cout << ans << endl;
}