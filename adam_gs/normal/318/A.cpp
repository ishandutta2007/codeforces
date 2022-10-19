#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	long long n, k;
	cin >> n >> k;
	if(k<=(n+1)/2) {
		cout << k*2-1;
	} else {
		k-=(n+1)/2;
		cout << k*2;
	}
}