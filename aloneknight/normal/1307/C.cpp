#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;ll a[30][30],c[30];char s[100005];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)a[j][s[i]-'a']+=c[j];
		c[s[i]-'a']++;
	}
	ll mx=0;
	for(int i=0;i<26;i++)mx=max(mx,c[i]);
	for(int i=0;i<26;i++)for(int j=0;j<26;j++)mx=max(mx,a[i][j]);
	printf("%lld\n",mx);
	return 0;
}