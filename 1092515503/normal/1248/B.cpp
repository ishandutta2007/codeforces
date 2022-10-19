#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[100010],s1,s2;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",num+i);
	sort(num+1,num+n+1);
	for(int i=1;i<=n/2;i++)s1+=num[i];
	for(int i=n;i>n/2;i--)s2+=num[i];
	printf("%lld\n",s1*s1+s2*s2);
	return 0;
}