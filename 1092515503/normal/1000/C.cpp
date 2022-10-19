#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
typedef long long ll;
int n,tag[4001000],m;
ll res[200100];
pair<ll,ll>p[200100];
vector<ll>v;
void pushdown(int x){
	tag[lson]+=tag[x],tag[rson]+=tag[x],tag[x]=0;
}
void modify(int x,int l,int r,int L,int R){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){tag[x]++;return;}
	pushdown(x),modify(lson,l,mid,L,R),modify(rson,mid+1,r,L,R);
}
void iterate(int x,int l,int r){
	if(l==r){/*printf("%d %d %d\n",l,r,tag[x]);*/res[tag[x]]+=v[l]-v[l-1];return;}
	pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r);
}
int main(){
	scanf("%d",&n),v;
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&p[i].first,&p[i].second),p[i].second++,v.push_back(p[i].first),v.push_back(p[i].second);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),m=v.size()-1;
//	for(int i=0;i<=m;i++)printf("%d ",v[i]);puts("");
	for(int i=1;i<=n;i++)p[i].first=lower_bound(v.begin(),v.end(),p[i].first)-v.begin()+1,p[i].second=lower_bound(v.begin(),v.end(),p[i].second)-v.begin();
	for(int i=1;i<=n;i++)modify(1,1,m,p[i].first,p[i].second);
	iterate(1,1,m);
	for(int i=1;i<=n;i++)printf("%I64d ",res[i]);
	return 0;
}