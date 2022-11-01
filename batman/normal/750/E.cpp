#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)

struct Node
{
	ll a[4][4];
	Node(){for(int i=0;i<4;i++)for(int j=0;j<4;j++)a[i][j]=0;}
};

ll n,q;
string s;
Node seg[4*N];

Node merge(Node x,Node y)
{
	Node res;
	for(int i=0;i<4;i++)
		for(int j=i;j<4;j++)
		{
			res.a[i][j]=N;
			for(int k=i;k<=j;k++)
				res.a[i][j]=min(res.a[i][j],x.a[i][k]+y.a[k][j]);
		}
	return res;
}

void build(ll xl=0,ll xr=n,ll id=1)
{
	if(xr-xl==1)
	{
		if(s[xl]=='2')seg[id].a[0][0]=1;
		if(s[xl]=='0')seg[id].a[1][1]=1;
		if(s[xl]=='1')seg[id].a[2][2]=1;
		if(s[xl]=='6')seg[id].a[3][3]=1;
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

Node query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return {};
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	return merge(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

set <ll> st[10];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q>>s;
	for(int i=0;i<n;i++)st[s[i]-'0'].insert(i);
	build();
	while(q--)
	{
		ll l,r,id1,id2,id3,id4;
		cin>>l>>r;l--;

		auto it=st[7].lower_bound(r);
		if(it==st[7].begin()){cout<<"-1\n";continue;}
		it--;id1=*it;

		it=st[1].lower_bound(id1);
		if(it==st[1].begin()){cout<<"-1\n";continue;}
		it--;id2=*it;
		
		it=st[0].lower_bound(id2);
		if(it==st[0].begin()){cout<<"-1\n";continue;}
		it--;id3=*it;

		it=st[2].lower_bound(id3);
		if(it==st[2].begin()){cout<<"-1\n";continue;}
		it--;id4=*it;

		if(id4<l){cout<<"-1\n";continue;}
		
		Node p1,p2,p3;
		p1=query(id3,id2);
		p2=query(id4,id3);
		p3=query(l,id4);
		ll ans=min(p1.a[3][3]+min({p2.a[1][3]+p3.a[0][1],p2.a[2][3]+p3.a[0][2],p2.a[3][3]+p3.a[0][3]}),
					p1.a[2][3]+min(p2.a[1][2]+p3.a[0][1],p2.a[2][2]+p3.a[0][2]));
		cout<<ans+query(id1,r).a[3][3]+query(id2,id1).a[3][3]<<"\n";

	}
	return 0;
}