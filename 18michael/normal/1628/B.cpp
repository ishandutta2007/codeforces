#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
bool ok;
int l[100002],Hs[100002],rHs[100002];
char s[100002][4];
bool vis[30002],vis1[30002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ok=0,memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]);
			if((l[i]=strlen(s[i]))==1)
			{
				ok=1,--i,--n;
				continue;
			}
			for(int j=0;j<l[i];++j)s[i][j]-='a'-1;
			Hs[i]=rHs[i]=0;
			for(int j=0;j<l[i];++j)Hs[i]=Hs[i]*30+s[i][j];
			for(int j=l[i]-1;~j;--j)rHs[i]=rHs[i]*30+s[i][j];
			if(Hs[i]==rHs[i] || vis[rHs[i]])ok=1;
			vis[Hs[i]]=1;
		}
		memset(vis,0,sizeof(vis)),memset(vis1,0,sizeof(vis1));
		for(int i=1;i<=n;++i)
		{
			Hs[i]=rHs[i]=0;
			for(int j=0;j<2;++j)Hs[i]=Hs[i]*30+s[i][j];
			for(int j=l[i]-1;j>=l[i]-2;--j)rHs[i]=rHs[i]*30+s[i][j];
			if(l[i]==2)
			{
				if(vis1[rHs[i]])ok=1;
				vis[Hs[i]]=1;
			}
			else
			{
				if(vis[rHs[i]])ok=1;
				vis1[Hs[i]]=1;
			}
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}