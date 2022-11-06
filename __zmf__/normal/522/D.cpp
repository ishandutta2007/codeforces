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
const int N=5e5+9;
int st[21][N],n,a[N],now,m,cnt,L,R;
int lg[N],l[N],r[N];
map<int,int> mp;
inline void build()
{
	lg[0]=-1;
	memset(st,0x3f,sizeof(st));
	for(int i=1;i<=cnt;i++)
	{
		lg[i]=lg[i/2]+1;
		st[0][i]=r[i]-l[i];
	}
	for(int i=1;i<=20;i++)
		for(int j=1;j<=cnt-(1<<i)+1;j++)	
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int x,int y)
{
	int k=lg[y-x+1];
	return min(st[k][x],st[k][y-(1<<k)+1]);
}
signed main()
{
	n=read();now=n+1;m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)
		if(!mp[a[i]])mp[a[i]]=i;
		else if(now>mp[a[i]])now=mp[a[i]],l[++cnt]=i,r[cnt]=mp[a[i]],mp[a[i]]=i;
		else mp[a[i]]=i;
	for(int i=1;i<=cnt/2;i++)swap(l[i],l[cnt-i+1]),swap(r[i],r[cnt-i+1]);
	build();
	for(int i=1;i<=m;i++)
	{
		L=read(),R=read();
		int x=lower_bound(l+1,l+cnt+1,L)-l,y=upper_bound(r+1,r+cnt+1,R)-r-1;
		if(x<=y)printf("%d\n",query(x,y));
		else puts("-1");
	}
	return 0;
}