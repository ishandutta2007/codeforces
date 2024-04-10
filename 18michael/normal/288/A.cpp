#include<cstdio>
int n,k,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(k);
	if(k>n || (n>1 && k==1))return 0&puts("-1");
	if(n==1)return 0&puts("a");
	for(int i=1;i<=n-k+2;++i)printf("%c",(i&1? 0:1)+'a');
	for(int i=n-k+3;i<=n;++i)printf("%c",(i+k-n-1)+'a');
	return 0;
}