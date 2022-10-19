#include <bits/stdc++.h>
using namespace std;

long long s(long long a){
	if(a < 10) return a;
	return a%10 + s(a/10);
}

int main() {
	long long n;
	cin >> n;
	long long x = 9;
	if(n < x){
		cout << n << endl;
		return 0;
	}
	while(x<=n){
		x += 9*(x+1);
	}
	x/=10;
	cout << s(x) + s(n-x);
	return 0;
}