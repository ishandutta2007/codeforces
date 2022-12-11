#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int v[30];
char s[maxn];
map<long long,int> mp;
int main()
{
	for(int i=0;i<26;++i)
		scanf("%d",v+i);
	scanf("%s",s+1);
	int n=strlen(s+1);
	long long val,ans=0;
	for(int i=1;i<=n;i++)
		if(v[s[i]-'a']==0)
			ans--;
	for(char t='a';t<='z';++t)
	{
		mp.clear();
		val=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==t)
				mp[val]++;
			val+=v[s[i]-'a'];
			if(s[i]==t)
				ans+=mp[val-v[s[i]-'a']*2];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}