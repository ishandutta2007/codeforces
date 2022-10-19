#include<bits/stdc++.h>
using namespace std;
int n,mx,Testnum,ok;
char s[200002];
bool u[200002];
vector<int> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Testnum);
	while(Testnum--)
	{
		read(n),scanf("%s",s+1),mx=0,ok=1,vec.clear();
		for(int i=1;i<=n;++i)s[i]-='0',u[i]=1;
		for(int i=0;i<10;++i)
		{
			for(int j=n;j;--j)
				if(s[j]==i)
				{
					if(j<mx)
					{
						mx=-1;
						break;
					}
					u[j]=0;
				}
			if(!(~mx))break;
			for(int j=n;j;--j)
				if(s[j]==i)
				{
					mx=j;
					break;
				}
		}
		for(int i=1;i<=n;++i)if(!u[i])vec.push_back(s[i]);
		for(int i=1;i<=n;++i)if(u[i])vec.push_back(s[i]);
		for(int i=1;i<n;++i)if(vec[i]<vec[i-1]){ok=0;break;}
		if(ok)for(int i=1;i<=n;++i)printf("%d",u[i]+1);
		else printf("-");puts("");
	}
	return 0;
}