#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=600005,P=998244353;
int n,p[N],q[N],ps[N],mx[N*4],s[N*4];
void upd(int x,int l,int r,int p,int v)
{
	if(l==r){s[x]+=v;mx[x]=s[x];return;}
	int mid=l+r>>1;
	if(p<=mid)upd(x<<1,l,mid,p,v);
	else upd(x<<1|1,mid+1,r,p,v);
	s[x]=s[x<<1]+s[x<<1|1];
	mx[x]=max(mx[x<<1|1],mx[x<<1]+s[x<<1|1]);
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]),ps[p[i]]=i;
	rep(i,1,n)scanf("%d",&q[i]);
	int m=n*2;upd(1,1,m,2*ps[n]-1,1);
	for(int i=1,j=n;i<=n;i++)
	{
		printf("%d ",j);upd(1,1,m,2*q[i],-1);
		while(mx[1]<=0){j--;upd(1,1,m,2*ps[j]-1,1);}
	}
	return 0;
}