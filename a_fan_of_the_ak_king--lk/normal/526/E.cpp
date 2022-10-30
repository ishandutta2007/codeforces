#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[2000005],fa[2000005],f[2000005],b,l,mx;
long long s[2000005];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main()
{
	n=read(),m=read();
	for(i=1;i<=n;++i)
	{
		fa[i]=i;
		a[i]=read();
		mx=max(mx,a[i]);
	}
	for(i=n+1;i<=n*2;++i)
		a[i]=a[i-n];
	for(i=1;i<=n*2;++i)
		s[i]=s[i-1]+a[i];
	while(m--)
	{
		b=read();
		l=0;
		for(i=n+1;i<=(n<<1);++i)
		{
			while(s[i]-s[l]>b)
				++l;
			fa[i]=fa[l];
			f[i]=f[l]+1;
			if(i-fa[i]>=n)
			{
				printf("%d\n",f[i]);
				break;
			}
		}
	}
}