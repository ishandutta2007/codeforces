#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int N=200005;
int T; 
map<LL,int> mp;
int cnt=0;
int n;
bool check (LL x)
{
	
	if (mp[x]!=0)	{mp[x]--;return true;}
	if (x==0) return false;
	if (x==1) return false;
	cnt++;
	if (cnt>n) return false;
	return check(x/2)&check((x+1)/2);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		mp.clear();
		cnt=0; 
		LL sum=0;
		scanf("%d",&n);
		for (int u=1;u<=n;u++) 
		{
			LL x;
			scanf("%lld",&x);
			mp[x]++;
			sum=sum+x;
		}
		if (check(sum)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}