#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100500
int n,k,v[N],s[N],st[N],ct,is2[N];
long long su1[N],su2[N];
struct segt1{
	struct node{int l,r;long long mx,lz,mn,mx2;}e[N*4];
	void pushdown(int x){if(!e[x].lz)return;e[x<<1].lz+=e[x].lz;e[x<<1].mx+=e[x].lz;e[x<<1].mn+=e[x].lz;e[x<<1|1].mn+=e[x].lz;e[x<<1|1].lz+=e[x].lz;e[x<<1|1].mx+=e[x].lz;e[x].lz=0;}
	long long query1(int x,long long v)
	{
		if(e[x].mx<=v)return v-e[x].mx2;
		if(e[x].l==e[x].r)return e[x].mx-e[x].mx2;
		pushdown(x);
		if(e[x<<1].mx<=v)return min(query1(x<<1|1,v),v-e[x<<1].mx2);
		else return min(query1(x<<1,v),e[x].mn);
	}
	void pushup(int x)
	{
		e[x].mn=query1(x<<1|1,e[x].mx);
		e[x].mx=max(e[x<<1].mx,e[x<<1|1].mx);
	}
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;
		if(l==r){e[x].mx=e[x].mx2=su1[l];return;}
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		e[x].mx2=max(e[x<<1].mx2,e[x<<1|1].mx2);pushup(x);
	}
	void modify(int x,int l,int r,long long v)
	{
		if(r<l)return;
		if(l<1)l=1;
		if(e[x].l==l&&e[x].r==r){e[x].lz+=v;e[x].mx+=v;e[x].mn+=v;return;}
		pushdown(x);
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)modify(x<<1,l,r,v);
		else if(mid<l)modify(x<<1|1,l,r,v);
		else modify(x<<1,l,mid,v),modify(x<<1|1,mid+1,r,v);
		pushup(x);
	}
	pair<long long,long long> query2(int x,int l,int r,long long v)
	{
		if(e[x].l==l&&e[x].r==r)return make_pair(query1(x,v),max(e[x].mx,v));
		pushdown(x);
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return query2(x<<1,l,r,v);
		else if(mid<l)return query2(x<<1|1,l,r,v);
		else
		{
			pair<long long,long long> st=query2(x<<1,l,mid,v),st2=query2(x<<1|1,mid+1,r,st.second);
			return make_pair(min(st.first,st2.first),st2.second);
		}
	}
}tr1;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)su1[i]=su2[i-1]+v[i],su2[i]=su1[i]-s[i];
	tr1.build(1,1,n);
	int as=1;st[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(ct&&su2[st[ct]]>=su2[i-1])tr1.modify(1,st[ct],st[ct-1]-1,su2[st[ct]]),is2[st[ct]]=0,ct--;
		tr1.modify(1,i-1,st[ct]-1,-su2[i-1]);st[++ct]=i-1;is2[i-1]=ct;
		tr1.modify(1,i,n,su2[i-1]);
		int lb=i,rb=n,as1=i;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1,fg1=is2[mid];
			if(fg1)
			tr1.modify(1,st[fg1],st[fg1-1]-1,su2[st[fg1]]);
			if(tr1.query2(1,mid,n,tr1.query2(1,i,mid,-1e17).second).first<=k)as1=mid,lb=mid+1;
			else rb=mid-1;
			if(fg1)tr1.modify(1,st[fg1],st[fg1-1]-1,-su2[st[fg1]]);
		}
		if(as<as1-i+1)as=as1-i+1;
		tr1.modify(1,i,n,-su2[i-1]);
	}
	printf("%d\n",as);
}