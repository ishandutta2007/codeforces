#include<cstdio>
int n,m,ans,Test_num;
int rt[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),ans=m;
		for(int i=1;i<=n;++i)rt[i]=i;
		for(int i=1,x,y;i<=m;++i)
		{
			read(x),read(y);
			if(x==y){--ans;continue;}
			getroot(x),getroot(y);
			if((x=rt[x])==(y=rt[y]))++ans;
			else rt[x]=y;
		}
		printf("%d\n",ans);
	}
	return 0;
}