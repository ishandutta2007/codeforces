#include<bits/stdc++.h>
using namespace std;
int n,m,t,la,Test_num;
int f[2][4];
struct aaa
{
	int x,y;
}p[200005];
inline bool cmp(aaa a,aaa b)
{
	return a.y==b.y? (a.x<b.x):(a.y<b.y);
}
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void upd(int x,int a,int b,int c,int d)
{
	f[x][0]=a,f[x][1]=b,f[x][2]=c,f[x][3]=d;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),la=t=0;
		for(int i=1;i<=m;++i)read(p[i].x),read(p[i].y);
		sort(p+1,p+m+1,cmp),p[++m]=(aaa){1,n+1},p[++m]=(aaa){2,n+1},upd(1,1,0,0,1);
		for(int i=1;i<=m;++i,t^=1)
		{
			if((p[i].y-la-1)&1)upd((t^1),(f[t^1][0]|f[t^1][3]),f[t^1][2],f[t^1][1],(f[t^1][0]|f[t^1][3]));
			if(i<m && p[i].y==p[i+1].y)upd(t,0,0,0,f[t^1][3]),++i;
			else if(p[i].x==1)upd(t,0,0,f[t^1][3],f[t^1][2]);
			else upd(t,0,f[t^1][3],0,f[t^1][1]);
			la=p[i].y;
		}
		puts(f[t][3]? "YES":"NO");
	}
	return 0;
}