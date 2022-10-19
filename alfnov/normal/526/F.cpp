#include<bits/stdc++.h>
using namespace std;
int a[300005],sm1[1200005],sm2[1200005],tag[1200005];
stack<int>s1,s2;
void pushdown(int o)
{
	tag[o<<1]+=tag[o],tag[o<<1|1]+=tag[o];
	sm1[o<<1]+=tag[o],sm1[o<<1|1]+=tag[o];
	tag[o]=0;
}
void build(int l,int r,int o)
{
	if(l==r)
	{
		sm2[o]=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,o<<1),build(mid+1,r,o<<1|1);
	sm2[o]=sm2[o<<1]+sm2[o<<1|1];
}
void add(int l,int r,int o,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		sm1[o]+=v,tag[o]+=v;
		return;
	}
	pushdown(o);
	int mid=l+r>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,v);
	if(sm1[o<<1]==sm1[o<<1|1])sm1[o]=sm1[o<<1],sm2[o]=sm2[o<<1]+sm2[o<<1|1];
	else if(sm1[o<<1]<sm1[o<<1|1])sm1[o]=sm1[o<<1],sm2[o]=sm2[o<<1];
	else
{
sm1[o]=sm1[o<<1|1],sm2[o]=sm2[o<<1|1];
}}
pair<int,int> query(int l,int r,int o,int ll,int rr)
{
	if(l>=ll&&r<=rr)return make_pair(sm1[o],sm2[o]);
	pushdown(o);
	int mid=l+r>>1;
	if(mid>=ll&&!(mid<rr))return query(l,mid,o<<1,ll,rr);
	else if(!(mid>=ll)&&mid<rr)return query(mid+1,r,o<<1|1,ll,rr);
	pair<int,int> p1=query(l,mid,o<<1,ll,rr);
	pair<int,int> p2=query(mid+1,r,o<<1|1,ll,rr);
	if(p1.first==p2.first)return make_pair(p1.first,p1.second+p2.second);
	else if(p1.first<p2.first)return p1;
	else return p2;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u]=v;
	}
	build(1,n,1);
	while(s1.size())s1.pop();
	while(s2.size())s2.pop();
	s1.push(0),s2.push(0);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		add(1,n,1,i,i,i);
		int wz=i-1,rr;
		while(s1.size())
		{
			int d=s1.top();
			if(d<wz)add(1,n,1,d+1,wz,a[i]-rr);
			rr=a[d],wz=d;
			if(d==0||a[d]>a[i])break;
			s1.pop();
		}
		s1.push(i);
		wz=i-1;
		while(s2.size())
		{
			int d=s2.top();
			if(d<wz)add(1,n,1,d+1,wz,rr-a[i]);
			rr=a[d],wz=d;
			if(d==0||a[d]<a[i])break;
			s2.pop();
		}
		s2.push(i);
		ans+=query(1,n,1,1,i).second;
	}
	cout<<ans<<endl;
	return 0;
}