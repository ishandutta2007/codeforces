#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	return gcd(min(a, b), abs(a - b));
}
int main(){
	int a[2], n;
	cin >> a[0] >> a[1] >> n;
	bool round = 0;
	while(n){
		n -= gcd(n, a[round]);
		round ^= 1;
	}
	cout << (round ^ 1) << endl;
}