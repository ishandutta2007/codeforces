#include<cstdio>
#define LL long long
int t=0,len,Test_num;
LL res,res1;
int to[2522],val[52];
int g[52][12];
LL f[22][52][2522][2];
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
inline LL calc(LL x)
{
	if(!x)return 0;
	len=res=0,res1=1;
	for(LL i=x;i/=10;++len,res1*=10);
	for(int i=0;i<=len;++i)
		for(int j=1;j<=t;++j)
			for(int k=0;k<2520;++k)
				f[i][j][k][0]=f[i][j][k][1]=0;
	for(int i=len,y=x/res1;~i;--i)
	{
		if(i==len)
		{
			for(int j=1;j<y;++j)++f[i][to[j]][j][0];
			++f[i][to[y]][y][1];
		}
		else for(int j=1;j<10;++j)++f[i][to[j]][j][0];
		if(i)
		{
			x%=res1,res1/=10,y=x/res1;
			for(int j=1;j<=t;++j)
				for(int k=0;k<2520;++k)
					if(f[i][j][k][0] || f[i][j][k][1])
					{
						for(int o=0;o<10;++o)f[i-1][o? to[val[j]*o/g[j][o]]:j][(k*10+o)%2520][0]+=f[i][j][k][0];
						for(int o=0;o<y;++o)f[i-1][o? to[val[j]*o/g[j][o]]:j][(k*10+o)%2520][0]+=f[i][j][k][1];
						f[i-1][y? to[val[j]*y/g[j][y]]:j][(k*10+y)%2520][1]+=f[i][j][k][1];
					}
		}
	}
	for(int i=1;i<=t;++i)
		for(int j=0;j<2520;j+=val[i])
			res+=f[0][i][j][0]+f[0][i][j][1];
	return res;
}
int main()
{
	for(int i=1;i<10;i<<=1)
		for(int j=1;j<10;j*=3)
			for(int k=1;k<10;k*=5)
				for(int l=1;l<10;l*=7)
				{
					val[to[i*j*k*l]=(++t)]=i*j*k*l;
					for(int o=0;o<10;++o)g[t][o]=gcd(val[t],o);
				}
	scanf("%d",&Test_num);
	for(LL l,r;Test_num--;)scanf("%lld%lld",&l,&r),printf("%lld\n",calc(r)-calc(l-1));
	return 0;
}