#include<bits/stdc++.h>
using namespace std;
bitset<100005>bs[26];
char s[100005],t[100005],c[15];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)bs[s[i]-'a'][i]=1;
	int T;
	cin>>T;
	while(T--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x;
			scanf("%d%s",&x,c+1);
			bs[s[x]-'a'][x]=0,bs[(s[x]=c[1])-'a'][x]=1;
		}else
		{
			int l,r;
			scanf("%d%d%s",&l,&r,t+1);
			int m=strlen(t+1);
			bitset<100005>b=bs[t[1]-'a'];
			for(int i=2;i<=m;i++)b&=bs[t[i]-'a']>>(i-1);
			int ans=(b>>l<<(100005+l-(r-m+2))).count();
			printf("%d\n",ans);
			for(int i=1;i<=m;i++)t[i]=0;
		}
	}
	return 0;
}