#include<bits/stdc++.h>
using namespace std;
int n,m,res0,res1;
int mn[1002],mx[1002],val0[5002],val1[5002];
string t;
string s[5002],a[5002],opt[5002],b[5002];
map<string,int> mp;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(char s1[],char s2[])
{
	int l1=strlen(s1),l2=strlen(s2);
	if(l1!=l2)return 0;
	for(int i=0;i<l1;++i)
		if(s1[i]!=s2[i])
			return 0;
	return 1;
}
int main()
{
	read(n),read(m);
	for(int i=1,l;i<=n;++i)
	{
		cin>>s[i]>>t>>a[i],l=s[i].length(),mp[s[i]]=i;
		if(a[i][0]!='0' && a[i][0]!='1')cin>>opt[i]>>b[i];
	}
	for(int i=0,t;i<m;++i)
	{
		res0=res1=0,t=m-i-1;
		for(int j=1;j<=n;++j)
		{
			if(a[j][0]!='0' && a[j][0]!='1')
			{
				if(a[j][0]!='?')
				{
					if(b[j][0]=='?')
					{
						int k=mp[a[j]];
						if(opt[j][0]=='A')val0[j]=(val0[k]&0),res0+=val0[j],val1[j]=(val1[k]&1),res1+=val1[j];
						else if(opt[j][0]=='O')val0[j]=(val0[k]|0),res0+=val0[j],val1[j]=(val1[k]|1),res1+=val1[j];
						else val0[j]=(val0[k]^0),res0+=val0[j],val1[j]=(val1[k]^1),res1+=val1[j];
					}
					else
					{
						int k=mp[a[j]],k1=mp[b[j]];
						if(opt[j][0]=='A')val0[j]=(val0[k]&val0[k1]),res0+=val0[j],val1[j]=(val1[k]&val1[k1]),res1+=val1[j];
						else if(opt[j][0]=='O')val0[j]=(val0[k]|val0[k1]),res0+=val0[j],val1[j]=(val1[k]|val1[k1]),res1+=val1[j];
						else val0[j]=(val0[k]^val0[k1]),res0+=val0[j],val1[j]=(val1[k]^val1[k1]),res1+=val1[j];
					}
				}
				else
				{
					if(b[j][0]!='?')
					{
						int k=mp[b[j]];
						if(opt[j][0]=='A')val0[j]=(val0[k]&0),res0+=val0[j],val1[j]=(val1[k]&1),res1+=val1[j];
						else if(opt[j][0]=='O')val0[j]=(val0[k]|0),res0+=val0[j],val1[j]=(val1[k]|1),res1+=val1[j];
						else val0[j]=(val0[k]^0),res0+=val0[j],val1[j]=(val1[k]^1),res1+=val1[j];
					}
					else
					{
						if(opt[j][0]=='A')val0[j]=(0&0),res0+=val0[j],val1[j]=(1&1),res1+=val1[j];
						else if(opt[j][0]=='O')val0[j]=(0|0),res0+=val0[j],val1[j]=(1|1),res1+=val1[j];
						else val0[j]=(0^0),res0+=val0[j],val1[j]=(1^1),res1+=val1[j];
					}
				}
			}
			else val0[j]=a[j][t]-'0',val1[j]=a[j][t]-'0';
		}
		if(res0<res1)mn[i]=0,mx[i]=1;
		else if(res0>res1)mn[i]=1,mx[i]=0;
		else mn[i]=mx[i]=0;
	}
	for(int i=m-1;~i;--i)printf("%d",mn[i]);puts("");
	for(int i=m-1;~i;--i)printf("%d",mx[i]);
	return 0;
}