#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main () {
	lli n,k;
	cin >> n >> k;
	lli sum=n+k,a=2,now=2;
	while (a<sum) {
		now++;
		a+=now;
	}
	cout << n-now+1 << endl;
}