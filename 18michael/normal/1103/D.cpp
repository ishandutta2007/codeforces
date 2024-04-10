#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,mp_t=0,Mx,N=0,i0=0,i1=1;
LL k,t=0,ans=inf;
LL a[1000002],u[4096];
int e[1000002],id[1000002],tmp[12],lg[4096],num[11602],num2[4096];
int cnt[11602][12];
LL f[2][12][4096];
bitset<4096> bs[11602];
LL pw[12][42];
vector<LL> vec;
unordered_map<LL,int> mp;
typedef pair<int,int> P;
vector<P> Vec;
inline bool cmp(int x,int y)
{
	return e[x]<e[y]? 1:0;
}
inline LL gcd(LL x,LL y)
{
	return y? gcd(y,x%y):x;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void ins(LL x)
{
	pw[N][0]=1;
	for(int i=0;(pw[N][i+1]=pw[N][i]*x)<=1000000000000LL;++i);
	for(++N,vec.push_back(x);!(t%x);t/=x);
}
inline void upd(int x,int y,LL z)
{
	if(z<f[i1][x][y])f[i1][x][y]=z,Vec.push_back(P(x,y));
}
int main()
{
	scanf("%d%lld",&n,&k),lg[0]=-1,u[0]=1;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),t=gcd(t,a[i]),id[i]=i;
	for(int i=1;i<=n;++i)scanf("%d",&e[i]);
	for(int i=2;i<=t/i;++i)if(!(t%i))ins(i);
	if(t>1)ins(t);
	Mx=(1<<N)-1,sort(id+1,id+n+1,cmp);
	for(int i=1;i<=Mx;i<<=1)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i)
	{
		t=1;
		for(int j=0;j<N;++j)for(tmp[j]=0;!(a[id[i]]%vec[j]);t*=vec[j],a[id[i]]/=vec[j],++tmp[j]);
		if(!mp.count(a[id[i]]=t))
		{
			mp[t]=(++mp_t);
			for(int j=0;j<N;++j)cnt[mp_t][j]=tmp[j];
		}
		if(num[mp[t]]<N)++num[mp[t]];
		else a[id[i]]=-1;
	}
	for(int i=1;i<=mp_t;++i)
		for(int j=1,j0;j<=Mx;++j)
		{
			j0=lowbit(j);
			if((u[j]=u[j^j0]*pw[lg[j0]][cnt[i][lg[j0]]])<=k)bs[i].set(j);
		}
	for(int i=0;i<=N;++i)for(int j=0;j<=Mx;++j)f[0][i][j]=f[1][i][j]=inf;
	f[0][0][0]=f[1][0][0]=0;
	for(int i=1,p;i<=n;++i)
		if(~a[id[i]])
		{
			p=mp[a[id[i]]],i0^=1,i1^=1;
			for(int l=0;l<Vec.size();++l)f[i1][Vec[l].first][Vec[l].second]=f[i0][Vec[l].first][Vec[l].second];
			Vec.clear();
			for(int j=bs[p]._Find_first();j<=Mx;j=bs[p]._Find_next(j))
				if(num2[j]<N)
				{
					++num2[j];
					for(int l=Mx^j;;(--l)&=(Mx^j))
					{
						for(int o=0;o<N;++o)upd(o+1,l|j,f[i0][o][l]+e[id[i]]);
						if(!l)break;
					}
				}
		}
	for(int i=0;i<=N;++i)if(f[i1][i][Mx]<inf)ans=min(ans,f[i1][i][Mx]*i);
	return 0&printf("%lld",ans==inf? -1:ans);
}