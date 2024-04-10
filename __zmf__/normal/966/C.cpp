//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9,INF=1e13;
int n,a[N],sum,b[N],ans[N],flag;
vector<int> t[N]; 
int now[N],cnt,pown[N];
bool vis[N];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum^=a[i];
	for(int j=1;j<=n;j++)
		for(int i=61;i>=0;i--)
			if(((a[j]>>i)&1))
			{
				t[i].push_back(j);
				break;
			}
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=0;j<=61;j++)
			if((((sum>>j)&1))&&(!t[j].empty()))
			{
			//	cout<<j<<endl;
				if(t[j].size()==0)continue;
				ans[++cnt]=t[j].back();
				sum^=a[t[j].back()];
				t[j].pop_back();flag=1;
				break;
			}
		if(!flag)
		{
			puts("No");return 0;
		}
	}
	if(cnt!=n)
	{
		puts("No");return 0;
	}
	puts("Yes");
	for(int i=n;i>=1;i--)printf("%lld ",a[ans[i]]);
	return 0;
}