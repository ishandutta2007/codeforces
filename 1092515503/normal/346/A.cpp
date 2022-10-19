#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[101],gcd,sum;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
	sort(num+1,num+n+1);
	gcd=num[1];
	for(int i=2;i<=n;i++)gcd=__gcd(gcd,num[i]-num[i-1]);
	for(int i=1;i<=n;i++)sum+=(num[i]-num[i-1])/gcd-1;
	puts(sum&1?"Alice":"Bob");
	return 0;
}