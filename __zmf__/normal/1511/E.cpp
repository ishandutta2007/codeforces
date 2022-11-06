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
const int mod=998244353;
int n,m,cnt,ans;
int p[300009];
int pown[300009];
char x[300009];
vector<int> a[300009];
signed main()
{
	n=read(),m=read();
	for(int i=0;i<n;i++)
	{
		cin>>x;
		for(int j=0;j<m;j++)
			if(x[j]=='*')
			{
				a[i].push_back(0);
			}
			else
			{
				a[i].push_back(1);cnt++;		
			}
	}	
	pown[0]=1;
	for(int i=1;i<=n*m;i++)pown[i]=pown[i-1]*2%mod;
	p[2]=1,p[3]=3;
	for(int i=4;i<=n*m;i++)p[i]=(p[i-1]+2*p[i-2]+pown[i-2])%mod;
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int j=0;j<m;j++)
			if(a[i][j]==1)now++;
			else 
			{
				if(now>=2)ans=(ans+p[now]*pown[cnt-now]%mod)%mod;
	//			cout<<now<<endl;
				now=0;
			}
	//	cout<<now<<endl;
		if(now>=2)ans=(ans+p[now]*pown[cnt-now]%mod)%mod;
	//	cout<<ans<<endl;
	}
	for(int i=0;i<m;i++)
	{
		int now=0;
		for(int j=0;j<n;j++)
			if(a[j][i]==1)now++;
			else 
			{
				if(now>=2)ans=(ans+p[now]*pown[cnt-now]%mod)%mod;
			//	cout<<now<<endl;
				now=0;
			}
		//cout<<now<<endl;
		if(now>=2)ans=(ans+p[now]*pown[cnt-now]%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}