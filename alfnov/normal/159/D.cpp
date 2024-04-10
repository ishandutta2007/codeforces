#include<bits/stdc++.h>
using namespace std;
char ss[2000005],s[4000005];
int m,n=0,l[4000005],c[4000005];
long long d[4000005],e[4000005];
void add(int x,int s)
{
	while(x<=n)
	{
		c[x]+=s;
		x+=x&-x;
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	scanf("%s",ss+1);
	m=strlen(ss+1);
	for(int i=1;i<=m;i++)s[++n]='#',s[++n]=ss[i];
	s[++n]='#';
	l[1]=1;
	int p0=1,p=1;
	for(int i=2;i<=n;i++)
	{
		if(i<=p)
		{
			int j=2*p0-i;
			if(j-l[j]>p0-l[p0])l[i]=l[j];
			else
			{
				int ii=p;
				while(ii<=n&&2*i>ii&&s[ii]==s[2*i-ii])ii++;
				l[i]=ii-i;
			}
		}else
		{
			int ii=i;
			while(ii<=n&&2*i>ii&&s[ii]==s[2*i-ii])ii++;
			l[i]=ii-i;
		}
		if(i+l[i]-1>=p)p0=i,p=i+l[i]-1;
	}
	for(int i=1;i<=n;i++)
	{
		add(i+l[i]-1,1);
		if(d[i]!='#')d[i]=query(n)-query(i-1);
		else d[i]=d[i-1];
	}
	memset(c,0,sizeof(c));
	for(int i=n;i>=1;i--)
	{
		add(i-l[i]+1,1);
		if(s[i]!='#')e[i]=e[i+1]+query(i);
		else e[i]=e[i+1];
	}
	long long aa=0;
	for(int i=1;i<m;i++)
	{
		aa+=d[2*i]*e[2*i+2];
	}
	cout<<aa<<endl;
	return 0;
}