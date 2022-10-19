#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,at,bt,anum,bnum,ans,Test_num;
int a[102],b[102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int abs(int x)
{
	return x>0? x:-x;
}
inline bool cmp(int a,int b)
{
	int a1=abs(a),b1=abs(b);
	return a1<b1? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),at=bt=anum=bnum=ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if((i^j)&1)read(a[++at]),anum+=(a[at]<=0? 1:0),ans+=abs(a[at]);
				else read(b[++bt]),bnum+=(b[bt]<=0? 1:0),ans+=abs(b[bt]);
			}
		sort(a+1,a+at+1,cmp),sort(b+1,b+bt+1,cmp);
		if((anum&1 && !(bnum&1)) || (bnum&1 && !(anum&1)))ans-=2*min(abs(a[1]),abs(b[1]));
		printf("%d\n",ans);
	}
	return 0;
}