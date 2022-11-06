//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9;
int n,k,q,l,r;
int p[200009],tree[400009];
inline int lowbit(int x){return x&(-x);}
inline void add(int x)
{
	while(x<=N)tree[x]++,x+=lowbit(x);
	return ;
}
inline int query(int x)
{
	int res=0;
	while(x!=0)res+=tree[x],x-=lowbit(x);
	return res;
}
int main()
{
	n=read(),k=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		l=read(),r=read();
		p[l]++;p[r+1]--;
	}
	for(int i=1;i<=N/2;i++)
	{
		p[i]=p[i-1]+p[i];
		if(p[i]>=k)
		{
//			cout<<i<<" "<<p[i]<<endl;
		//	cout<<i<<endl;
			add(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		l=read(),r=read();
		printf("%d\n",query(r)-query(l-1));
	}
	return 0;
}