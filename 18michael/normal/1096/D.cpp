#include<cstdio>
#define LL long long
int n;
LL a,ans=0;
int la[4]={};
LL f[4]={};
char s[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	read(n),scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		read(a),ans+=a;
		switch(s[i])
		{
			case 'h':f[1]=max(f[1],f[0])+a,f[2]+=a,f[3]+=a;break;
			case 'a':f[0]+=a,f[2]=max(f[2],f[1])+a,f[3]+=a;break;
			case 'r':f[0]+=a,f[1]+=a,f[3]=max(f[3],f[2])+a;break;
			case 'd':f[0]+=a,f[1]+=a,f[2]+=a;break;
			default:ans-=a;break;
		}
	}
	ans-=max(max(f[0],f[1]),max(f[2],f[3])),printf("%lld",ans);
	return 0;
}