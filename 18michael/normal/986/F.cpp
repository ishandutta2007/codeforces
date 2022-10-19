#include<bits/stdc++.h>
#define Mx 31622776
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int p_t=0,Test_num;
LL tmp,inv;
int id[10002],p[1951962];
bool ans[10002],u[Mx+2];
LL n[10002],k[10002],mn[100002];
vector<LL> vec;
typedef pair<LL,int> P;P pr;
priority_queue<P,vector<P> > pq;
inline bool cmp(int x,int y)
{
	return k[x]<k[y]? 1:0;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
inline LL Pow(LL a,int b,LL mod)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1),mod);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	init(),scanf("%d",&Test_num);
	for(int i=1;i<=Test_num;++i)scanf("%lld%lld",&n[i],&k[i]),id[i]=i;
	sort(id+1,id+Test_num+1,cmp);
	for(int i=1,j;i<=Test_num;i=j)
	{
		tmp=k[id[i]],vec.clear();
		for(int l=1;l<=p_t;++l)if(!(tmp%p[l]))for(vec.push_back(p[l]);!(tmp%p[l]);)tmp/=p[l];
		if(tmp>1)vec.push_back(tmp);
		if(vec.size()==2)inv=Pow(vec[1]%vec[0],vec[0]-2,vec[0]);
		else if(vec.size()>2)
		{
			for(int i=0;i<vec[0];++i)mn[i]=inf;
			for(pq.push(P(mn[0]=0,0));!pq.empty();)
			{
				pr=pq.top(),pq.pop();
				for(int i=1;i<vec.size();++i)if(mn[(vec[i]+pr.second)%vec[0]]>pr.first+vec[i])pq.push(P(mn[(vec[i]+pr.second)%vec[0]]=pr.first+vec[i],(vec[i]+pr.second)%vec[0]));
			}
		}
		for(j=i;j<=Test_num && k[id[j]]==k[id[i]];++j)
		{
			if(vec.size()==1)ans[id[j]]=!(n[id[j]]%k[id[j]]);
			else if(vec.size()==2)ans[id[j]]=(n[id[j]]>=((inv*(n[id[j]]%vec[0]))%vec[0])*vec[1]);
			else if(vec.size()>2)ans[id[j]]=(mn[n[id[j]]%vec[0]]<=n[id[j]]);
		}
	}
	for(int i=1;i<=Test_num;++i)puts(ans[i]? "YES":"NO");
	return 0;
}