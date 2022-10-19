#include<cstdio>
#define LL long long
int n,m,Mx,ans;LL res;
LL one[1048576]={},cnt[1048576]={};
char ch[22][100002];
inline LL min(LL x,LL y)
{
	return x<y? x:y;
}
inline void mul(LL a[],LL b[])
{
	for(int i=0;i<=Mx;++i)a[i]*=b[i];
}
inline void XOR(LL a[])
{
	LL t;
	for(int i=1;i<=Mx;i<<=1)
		for(int j=0;j<=Mx;j+=(i<<1))
			for(int k=0;k<i;++k)
				t=a[j+k],a[j+k]=t+a[i+j+k],a[i+j+k]=t-a[i+j+k];
}
inline void IXOR(LL a[])
{
	LL t;
	for(int i=1;i<=Mx;i<<=1)
		for(int j=0;j<=Mx;j+=(i<<1))
			for(int k=0;k<i;++k)
				t=a[j+k],a[j+k]=(t+a[i+j+k])/2,a[i+j+k]=(t-a[i+j+k])/2;
}
int main()
{
	scanf("%d%d",&n,&m),Mx=(1<<n)-1,ans=n*m;
	for(int i=1;i<=Mx;++i)one[i]=one[i>>1]+(i&1);
	for(int i=0,j;i<=Mx;++i)j=(Mx^i),one[i]=one[j]=min(one[i],one[j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			do ch[i][j]=getchar();while(ch[i][j]!='0' && ch[i][j]!='1');
	for(int i=1;i<=m;++i)
	{
		res=0;
		for(int j=1;j<=n;++j)res=((res<<1)|(ch[j][i]^48));
		++cnt[res];
	}
	XOR(one),XOR(cnt),mul(cnt,one),IXOR(cnt);
	for(int i=0;i<=Mx;++i)ans=min(ans,cnt[i]);
	return 0&printf("%d",ans);
}