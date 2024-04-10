#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[300005],cnt[300005],seg[3][1200005],lazy[1200005],n;
multiset<int> ms;

void modify(int L,int R,int l,int r,int rt,int val)
{
	if(L<=l&&R>=r)
		return lazy[rt]+=val,void();
	int m=l+r>>1;
	if(L<=m) modify(L,R,l,m,rt<<1,val);
	if(R>m) modify(L,R,m+1,r,rt<<1|1,val);
	
	seg[0][rt]=0;
	if(lazy[rt<<1]) seg[0][rt]+=m-l+1;
	else seg[0][rt]+=seg[0][rt<<1];
	if(lazy[rt<<1|1]) seg[0][rt]+=r-m;
	else seg[0][rt]+=seg[0][rt<<1|1];
	
	seg[1][rt]=0;
	if(lazy[rt<<1]>1) seg[1][rt]+=m-l+1;
	else if(lazy[rt<<1]==1) seg[1][rt]+=seg[0][rt<<1];
	else seg[1][rt]+=seg[1][rt<<1];
	if(lazy[rt<<1|1]>1) seg[1][rt]+=r-m;
	else if(lazy[rt<<1|1]==1) seg[1][rt]+=seg[0][rt<<1|1];
	else seg[1][rt]+=seg[1][rt<<1|1];
	
	seg[2][rt]=0;
	if(lazy[rt<<1]>2) seg[2][rt]+=m-l+1;
	else if(lazy[rt<<1]==2) seg[2][rt]+=seg[0][rt<<1];
	else if(lazy[rt<<1]==1) seg[2][rt]+=seg[1][rt<<1];
	else seg[2][rt]+=seg[2][rt<<1];
	if(lazy[rt<<1|1]>2) seg[2][rt]+=r-m;
	else if(lazy[rt<<1|1]==2) seg[2][rt]+=seg[0][rt<<1|1];
	else if(lazy[rt<<1|1]==1) seg[2][rt]+=seg[1][rt<<1|1];
	else seg[2][rt]+=seg[2][rt<<1|1];
}

void range(int a,int b,int v)
{
	//cout << "[" << a << "," << b << "] += " << v << "\n";
	modify(a,b,1,n,1,v);
}

int gv(int x,int mx)
{
	int rt;
	if(x>1) range(1,x-1,3);
	if(mx<n) range(mx+1,n,3);
	if(lazy[1]>2) rt=0;
	else if(lazy[1]==2) rt=n-seg[0][1];
	else if(lazy[1]==1) rt=seg[0][1]-seg[1][1];
	else rt=seg[1][1]-seg[2][1];
	if(x>1) range(1,x-1,-3);
	if(mx<n) range(mx+1,n,-3);
	return rt;
}

int main()
{jizz
	ll ans=0;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<=n;++i)
		range(i,n,3);
	for(int i=1,j=1;i<=n;++i)
	{
		++cnt[arr[i]],ms.insert(arr[i]);
		while(cnt[arr[i]]>1)
		{
			if(j+1<i)
			{
				range(arr[j],n,-1);
				if(arr[j+1]>arr[j]) range(arr[j],arr[j+1]-1,-1);
				else range(arr[j+1],arr[j]-1,-1);
				range(arr[j+1],n,1);
			}
			else
				range(arr[j],n,-2);
			ms.erase(ms.find(arr[j])),range(arr[j],n,3),--cnt[arr[j]],++j;
		}
		range(arr[i],n,-3);
		if(i>j)
		{
			range(arr[i-1],n,-1);
			if(arr[i]>arr[i-1]) range(arr[i-1],arr[i]-1,1);
			else range(arr[i],arr[i-1]-1,1);
		}
		else
			range(arr[i],n,1);
		range(arr[i],n,1);
		int x=gv(arr[i],*ms.rbegin());
		ans+=x;//,cout << i << ": " << x << "\n";
	}
	cout << ans << "\n";
}