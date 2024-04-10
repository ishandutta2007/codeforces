#include<cstdio>
int n,n1,sum,ans_t=0;
int a[100002];
struct aaa
{
	int x,y,z;
}ans[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),n1=n-(n&1? 0:1);
	for(int i=1;i<=n;++i)read(a[i]),sum^=a[i];
	if(!(n&1) && sum)return 0&puts("NO");
	for(int i=2;i<=n1;i+=2)ans[++ans_t]=(aaa){i-1,i,n1};
	for(int i=2;i<=n1;i+=2)ans[++ans_t]=(aaa){i-1,i,n1};
	printf("YES\n%d\n",ans_t);
	for(int i=1;i<=ans_t;++i)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
	return 0;
}