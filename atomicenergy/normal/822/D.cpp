#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

long long  ma = 5000001;
long long  mod = 1000000007;

int main() {
	long long b[5000001];
	long long ans[5000001];
	for(long long  i=0; i<ma; i++){
		b[i] = i;
	}
	for(long long  i=2; i<ma; i++){
		if(b[i] == i){
			for(long long  j=i*i; j<ma; j+=i){
				if(b[j] == j){
					b[j] = i;
				}
			}
		}
	}
	for(long long  i=2; i<ma; i++){
		if(b[i] == i){
			ans[i] = (i*(i-1))%mod;
		}
		else{
			ans[i] = (((i*(b[i]-1))%mod)+ans[(i/b[i])])%mod;
		}
	}
	long long sum = 0;
	long long exp = 1;
	long long  l, r, t;
	cin >> t >> l >> r;
	for(long long  i=l; i<=r; i++){
		//cout << i << " " << ans[i] << endl;
		sum += (ans[i] * exp)%mod;
		sum %=mod;
		exp*=t;
		exp%=mod;
	}
	if(sum%2==0)
		sum/=2;
	else{
		sum+=mod;
		sum/=2;
		sum%=mod;
	}
	cout << sum << endl;
}