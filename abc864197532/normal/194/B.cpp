#include <bits/stdc++.h>
using namespace std;
#define lli long long int


lli gcd(lli n,lli m) {
	int tmp;
	while (n%m!=0) {
		n=n%m;
		tmp=m;
		m=n;
		n=tmp;
	}
	return m;
}

int main () {
	int t;
	lli n;
	cin >> t;
	for (int i=0;i<t;++i) {
		cin >> n;
		lli k=4*n,l=n+1;
		cout << k/gcd(k,l)+1 << endl;
	}
}