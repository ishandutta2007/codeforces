#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int query(int x1,int y1,int x2,int y2)
{
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int x;
	cin >> x;
	return x;
}

int main()
{jizz
	int n;
	pii odr=MP(-1,-1),odc=MP(-1,-1),ans[2]={MP(-1,-1),MP(-1,-1)};
	cin >> n;
	for(int i=1;i<n;++i)
	{
		if(query(i,1,i,n)&1)
			if(~odr.F) odr.S=i;
			else odr.F=i;
	}
	for(int i=1;i<n;++i)
	{
		if(query(1,i,n,i)&1)
			if(~odc.F) odc.S=i;
			else odc.F=i;
	}
	if(~odr.F&&!~odr.S) odr.S=n;
	if(~odc.F&&!~odc.S) odc.S=n;
	if(~odr.F&&~odc.F)
	{
		if(query(odr.F,odc.F,odr.F,odc.F)&1)
			ans[0]=MP(odr.F,odc.F);
		if(query(odr.F,odc.S,odr.F,odc.S)&1)
			if(~ans[0].F) ans[1]=MP(odr.F,odc.S);
			else ans[0]=MP(odr.F,odc.S);
		if(query(odr.S,odc.F,odr.S,odc.F)&1)
			if(~ans[0].F) ans[1]=MP(odr.S,odc.F);
			else ans[0]=MP(odr.S,odc.F);
		if(query(odr.S,odc.S,odr.S,odc.S)&1)
			if(~ans[0].F) ans[1]=MP(odr.S,odc.S);
			else ans[0]=MP(odr.S,odc.S);
	}
	else if(~odr.F)
	{
		int l=1,r=n;
		while(l<r)
		{
			int m=l+r>>1;
			if(query(odr.F,1,odr.F,m)&1) r=m;
			else l=m+1;
		}
		ans[0]=MP(odr.F,l);
		l=1,r=n;
		while(l<r)
		{
			int m=l+r>>1;
			if(query(odr.S,1,odr.S,m)&1) r=m;
			else l=m+1;
		}
		ans[1]=MP(odr.S,l);
	}
	else
	{
		int l=1,r=n;
		while(l<r)
		{
			int m=l+r>>1;
			if(query(1,odc.F,m,odc.F)&1) r=m;
			else l=m+1;
		}
		ans[0]=MP(l,odc.F);
		l=1,r=n;
		while(l<r)
		{
			int m=l+r>>1;
			if(query(1,odc.S,m,odc.S)&1) r=m;
			else l=m+1;
		}
		ans[1]=MP(l,odc.S);
	}
	cout << "! " << ans[0].F << " " << ans[0].S << " " << ans[1].F << " " << ans[1].S << endl;
}