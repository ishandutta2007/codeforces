#include <bits/stdc++.h>
using namespace std;
#define lli long long int
string nums[100000];
lli pp=10000000000%998244353;

lli pow1(int k) {
	int a=k%5;
	k/=5;
	return pow(100,a)*pow(pp,k);
}


int main () {
	lli n;
	cin >> n;
	for (int i=0;i<n;++i) cin >> nums[i];
	lli sum=0;
	int l=nums[0].length();
	for (int i=0;i<n;++i) {
		for (int j=l-1;j>=0;--j) {
			sum+=pow1(l-j-1)*(nums[i][j]-'0');
			sum%=998244353;
		}
	}
	sum*=11*n;
	cout << sum%998244353 << endl;
}