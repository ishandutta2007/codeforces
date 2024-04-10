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
const int N=2e5+9;
int n,a,b,k,tot;
char c[N];
struct point
{
	int l,r;
}q[N];
inline int work(int x)
{
	if(b==1)return x;
	else return x/b;
}
//**.**.**
signed main()
{
	n=read(),a=read(),b=read(),k=read();
	scanf("%s",c+1);
	int now=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='1'&&now!=0)q[++cnt].l=i-now,q[cnt].r=i-1,tot+=work(now),now=0;
		else if(c[i]=='0')now++;
	}
	if(now!=0)q[++cnt].l=n-now+1,q[cnt].r=n,tot+=work(now);
	cout<<tot-a+1<<endl;
	tot=tot-a+1;
	for(int i=1;i<=cnt;i++)
	{
		if(!tot)break;
		int now=q[i].l+b-1;
		while(now<=q[i].r&&tot)
		{
			tot--;printf("%d ",now);
			now=now+b;
		}
	}
	return 0;
}