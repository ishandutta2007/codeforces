#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
int taxi,n,a[N],ans[N],x,flag,res,now,cnt; 
vector<int>q[N];
int main()
{
	taxi=read();
	for(int i=1;i<=taxi;i++)
	{
		flag=0;
		n=read();
		for(int i=1;i<=n;i++)q[i].clear();
		res=n;
		//for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			q[a[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
			if(q[i].size()!=0)
			{
				now=0,cnt=0;
				for(int j=0;j<q[i].size();j++)
				{
					if(q[i][j]-now>=2)cnt++;
					now=q[i][j];
				}
				if(n+1-now>=2)cnt++;
				res=min(res,cnt);
			}
		printf("%d\n",res);
	}
	return 0;
}