#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int a = 0; a < (b); ++a)
int main() {
	long long n;
	cin >> n;
	if(n%2==1) cout << "-";
	cout << (n+1)/2;
}