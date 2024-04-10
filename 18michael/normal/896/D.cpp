#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,p,l,r,t,p1,l1,r1;
LL ans=0;
int val[200002];
LL fac[200002],inv[200002];
int cnt[200002][12];
LL pw[12][200002];
vector<int> vec;
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%p;
	if(b&1)c=(c*a)%p;
	return c;
}
inline LL C(int a,int b)
{
	if(b<0 || a<b)return 0;
	LL res=(((fac[a]*inv[b])%p)*inv[a-b])%p;
	for(int i=0;i<vec.size();++i)res=(res*pw[i][cnt[a][i]-cnt[b][i]-cnt[a-b][i]])%p;
	return res;
}
inline void ins(int x)
{
	pw[vec.size()][0]=1;
	for(int i=1;i<=n;++i)pw[vec.size()][i]=(pw[vec.size()][i-1]*x)%p;
	for(vec.push_back(x),p1=p1/x*(x-1);!(t%x);t/=x);
}
int main()
{
	scanf("%d%d%d%d",&n,&p,&l,&r),p1=t=p,fac[0]=1;
	for(int i=2;i*i<=t;++i)if(!(t%i))ins(i);
	if(t>1)ins(t);
	for(int i=1;i<=n;++i)
	{
		val[i]=i;
		for(int j=0;j<vec.size();++j)for(cnt[i][j]=cnt[i-1][j];!(val[i]%vec[j]);val[i]/=vec[j],++cnt[i][j]);
		fac[i]=(fac[i-1]*val[i])%p;
	}
	inv[n]=Pow(fac[n],p1-1);
	for(int i=n;i;--i)inv[i-1]=(inv[i]*val[i])%p;
	for(int i=0;i<=n;++i)ans=(ans+(C(i,(i-l-((i-l)&1))>>1)-C(i,((i-r+((i-r)&1))>>1)-1))*C(n,i))%p;
	return 0&printf("%lld",(ans+p)%p);
}