#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
struct segt
{
	ll mn,ad;
}tr[1111111];
ll min(ll x,ll y){return(x<y)?x:y;}
void pushu(int p)
{tr[p].mn=min(tr[p<<1].mn,tr[p<<1|1].mn);}
void push(int p,ll d){tr[p].ad+=d,tr[p].mn+=d;}
void pushd(int p)
{if(tr[p].ad)push(p<<1,tr[p].ad),push(p<<1|1,tr[p].ad),tr[p].ad=0;}
int n,m,q;
void modify(int l,int r,ll d,int p=1,int pl=1,int pr=n)
{
	if(l>pr||pl>r)return;
	if(pl>=l&&pr<=r)return push(p,d);
	int mid=(pl+pr)>>1;
	pushd(p),modify(l,r,d,p<<1,pl,mid),modify(l,r,d,p<<1|1,mid+1,pr),pushu(p);
}
ll cst[1111111],va[1111111],vb[1111111];
#include<set>
std::multiset<ll>S;
#include<vector>
int t[1111111],l[1111111];
std::vector<int>v[1111111];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	register int i;
	for(i=1;i<n;i++)scanf("%lld%lld",va+i,vb+i),modify(i+1,i+1,vb[i]);
	int x,y;
	for(i=1;i<=m;i++)scanf("%d%d%d",&x,t+i,l+i),v[x].push_back(i);
	for(i=1;i<=n;i++)
	{
		for(auto r:v[i])modify(1,t[r],l[r]);
		cst[i]=tr[1].mn;
	}for(i=1;i<=n;i++)
		S.insert(cst[i]+va[i]);
	printf("%lld\n",*S.begin());
	for(i=1;i<=q;i++)scanf("%d%d",&x,&y),
		S.erase(S.find(cst[x]+va[x])),va[x]=y,S.insert(cst[x]+y),
		printf("%lld\n",*S.begin());
}
/*
Just go for it.
*/