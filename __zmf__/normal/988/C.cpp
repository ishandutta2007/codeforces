//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int k,n,p,sum,qwq;
map<int,int> id;
vector<int> G[200009];
signed main()
{
	k=read();
	for(int i=1;i<=k;i++)
	{
		n=read();
		sum=0;
		for(int j=1;j<=n;j++)
		{
			p=read();sum+=p;G[i].push_back(p);
		}
		for(int j=0;j<n;j++)
		{	
			qwq=sum-G[i][j];
			if(id[qwq]==0||id[qwq]==i)id[qwq]=i;
			else 
			{
				int pp=id[qwq];
				puts("YES");
				cout<<i<<" "<<j+1<<endl;
				cout<<pp<<" ";
				sum=0;
				for(int p=0;p<G[pp].size();p++)sum+=G[pp][p];
				//cout<<sum<<endl;
				for(int p=0;p<G[pp].size();p++)
					if(sum-G[pp][p]==qwq)
					{
						cout<<p+1<<endl;
						return 0;
					}
			}
		}
	}
	puts("NO");
	return 0;
}