#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,Test_num;
LL res,sum;
map<LL,LL> mp;
int main()
{
	scanf("%d",&Test_num);
	for(int x;Test_num--;)
	{
		mp.clear(),res=0,scanf("%d",&n),sum=mp[0]=1;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&x),res+=x;
			if(!mp.count(x-res))mp[x-res]=sum;
			else sum=(sum-mp[x-res])%mod,mp[x-res]=(mp[x-res]+sum)%mod;
			sum=(sum+mp[x-res])%mod;
		}
		printf("%lld\n",(sum+mod)%mod);
	}
	return 0;
}