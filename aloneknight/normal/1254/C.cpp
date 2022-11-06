#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005;
int n,p[N];ll val[N];
vector<int>V1,V2,Va,Vb,Vc,Vd;
inline bool cmp(int a,int b){return val[a]>val[b];}
inline ll qry(int o,int i,int j,int k)
{
	printf("%d %d %d %d\n",o,i,j,k);fflush(stdout);
	ll w;scanf("%I64d",&w);return w;
}
int main()
{
	scanf("%d",&n);
	int x=1,y=rand()%(n-1)+2;
	for(int i=1;i<=n;i++)if(i!=x&&i!=y)
	{
		ll t=qry(2,x,y,i);
		if(t==1)V1.push_back(i);else V2.push_back(i);
	}
	for(int i=1;i<=n;i++)if(i!=x&&i!=y)val[i]=qry(1,x,y,i);
	sort(V1.begin(),V1.end(),cmp);
	sort(V2.begin(),V2.end(),cmp);
	if(V1.size())
	{
		for(int i=1;i<V1.size();i++)
		{
			ll t=qry(2,x,V1[0],V1[i]);
			if(t==1)Va.push_back(V1[i]);else Vd.push_back(V1[i]);
		}
	}
	if(V2.size())
	{
		for(int i=1;i<V2.size();i++)
		{
			ll t=qry(2,x,V2[0],V2[i]);
			if(t==1)Vc.push_back(V2[i]);else Vb.push_back(V2[i]);
		}
	}
	printf("0");int nn=0;
	for(int i=0;i<Va.size();i++)p[++nn]=Va[i];
	p[++nn]=x;
	for(int i=Vb.size()-1;~i;i--)p[++nn]=Vb[i];
	if(V2.size())p[++nn]=V2[0];
	for(int i=0;i<Vc.size();i++)p[++nn]=Vc[i];
	p[++nn]=y;
	for(int i=Vd.size()-1;~i;i--)p[++nn]=Vd[i];
	if(V1.size())p[++nn]=V1[0];
	for(int i=1;i<=n;i++)p[n+i]=p[i];
	for(int i=1;i<=n;i++)if(p[i]==1)
	{
		for(int j=i;j<n+i;j++)printf(" %d",p[j]);
		break;
	}
	return 0;
}