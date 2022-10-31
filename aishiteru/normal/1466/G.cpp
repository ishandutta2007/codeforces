#include<bits/stdc++.h>
using namespace std; 
const int N=1000005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,i,j,m,e,q;
char s[N],c[N],t[N];
long long ans=0,su[N],iv[N],ss[100005][26];
void cal(string c,int e,int p)
{
	if(c.size()==1)
	{
		ans=(ans+ss[e][c[0]-'a']-ss[p-1][c[0]-'a'])%M;
		return;
	}
	if(p>e)
		return;
	int i;
	for(i=0;i<c.size();i+=2)
		if(c[i]!=t[p])
			break;
	if(i>=c.size())
	{
		string u;
		for(i=1;i<c.size();i+=2)
			u=u+c[i];
		cal(u,e,p+1);
	}
	for(i=1;i<c.size();i+=2)
		if(c[i]!=t[p])
			break;
	if(i>=c.size())
	{
		string u;
		for(i=0;i<c.size();i+=2)
			u=u+c[i];
		cal(u,e,p+1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&q);
	scanf("%s",s);
	int l=strlen(s);
	scanf("%s",t+1);
	iv[0]=su[0]=1;
	for(i=1;i<=n;++i)
	{
		su[i]=su[i-1]*2%M;
		iv[i]=iv[i-1]*((M+1)/2)%M;
		for(j=0;j<26;++j)
			ss[i][j]=ss[i-1][j];
		ss[i][t[i]-'a']=(ss[i][t[i]-'a']+iv[i])%M;
	}
	while(q--)
	{
		scanf("%d",&e);
		scanf("%s",c);
		ans=0;
		for(i=0;i<=l;++i)
		{
			string y;
			int t=i;
			for(j=0;c[j];++j)
			{
				if(t==l)
					y=y+c[j];
				else
					if(s[t]!=c[j])
						break;
				t=(t+1)%(l+1);
			}
			if(!c[j])
				if(y.size()==0)
					++ans;
				else
					cal(y,e,1);
		}
		ans=ans*su[e]%M;
		printf("%lld\n",(ans%M+M)%M);
	}
}