#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)

struct Ant{
	ll x,y,id;
	char c;
};

bool cmp(Ant x,Ant y){return x.x<y.x;}

ll n,m,t,ans[N],cnt_l;
pair <ll,ll> b[N];
Ant a[N];
ll tmp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>t;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].c;
		a[i].id=i;
		a[i].y=a[i].x+(t%m)*(a[i].c=='R'?1:-1);
		if(a[i].y<=0)a[i].y+=m;
		if(a[i].y>m)a[i].y-=m;
		if(a[i].c=='L')cnt_l++;
	}
	sort(a,a+n,cmp);
	ll shift=2*n-2*cnt_l;shift%=n;
	shift*=t/m;shift%=n;t%=m;
	for(int i=0;i<n;i++)tmp[(i+shift)%n]=a[i].id;
	for(int i=0;i<n;i++)a[i].id=tmp[i];
	
	for(int i=0;i<n;i++)b[i]={a[i].y,i};
	sort(b,b+n);
	
	ll hits[2]={};
	for(int q=0;q<2;q++)
		for(int i=0;i<n;i++)
			if(a[i].c!=a[b[q].second].c)
			{
				ll p=b[q].second;
				ll l=a[p].x,r=a[p].y;
				ld pos1=((ld)a[p].x+a[i].x)/2,pos2=pos1+(ld)m/2;
				if(pos2>m)pos2-=m;
				if(l<=r && a[p].c=='R')hits[q]+=(l<pos1 && pos1<r)+(l<pos2 && pos2<r);
				if(l<=r && a[p].c=='L')hits[q]+=(pos1<l || r<pos1)+(pos2<l || r<pos2);
				if(r<l && a[p].c=='L')hits[q]+=(r<pos1 && pos1<l)+(r<pos2 && pos2<l);
				if(r<l && a[p].c=='R')hits[q]+=(pos1<r || l<pos1)+(pos2<r || l<pos2);
			}
	ll id1=(b[0].second+hits[0]*(a[b[0].second].c=='R'?1:-1)+5*n)%n,id2=(b[1].second+hits[1]*(a[b[1].second].c=='R'?1:-1)+5*n)%n;
	for(int i=id1,j=0;j<n;i++,i%=n,j++)
		ans[a[i].id]=b[(j+(b[0].first==b[1].first && (id2+1)%n==id1))%n].first;
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}