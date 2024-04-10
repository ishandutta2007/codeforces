#include<cstdio>
#define R register
#define LL long long
int n,Test_num;
LL fac[100002],inv[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void write(int x) 
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline bool check(int x)
{
	for(R int i=2;i*i<=x;++i)
		if(!(x%i))
			return 0;
	return 1;
}
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%n;
	if(b&1)c=(c*a)%n;
	return c;
}
int main()
{
	fac[0]=1,read(n);
	if(n==1)puts("YES"),puts("1");
	else if(n==4)puts("YES"),puts("1\n3\n2\n4");
	else if(!check(n))puts("NO");
	else
	{
		for(R int i=1;i<n;++i)fac[i]=(fac[i-1]*i)%n;
		inv[n-1]=pow(fac[n-1],n-2);
		for(R int i=n-1;i;--i)inv[i-1]=(inv[i]*i)%n;
		puts("YES"),puts("1");
		for(R int i=2;i<n;++i)write((((fac[i]*inv[i-1])%n)*((inv[i-1]*fac[i-2])%n))%n),putchar('\n');
		write(n),putchar('\n');
	}
	return 0;
}