#include <bits/stdc++.h>
using namespace std;
int a[500005],mn[500005],mx[500005],s[500005],ssz;
const int inf=1e9;
struct stree
{
	struct node
	{
		int l,r;
		pair <int,int> mn,mx;
	}t[550005];
	inline void upd(int now)
	{
		t[now].mn=min(t[now*2].mn,t[now*2+1].mn);
		t[now].mx=max(t[now*2].mx,t[now*2+1].mx);
	}
	inline void build(int now,int l,int r)
	{
		t[now]={l,r,{0,0},{0,0}};
		if(l==r)
		{
			t[now].mn={a[l],l};
			t[now].mx={a[l],l};
			return ;
		}
		int mid=(l+r)/2;
		build(now*2,l,mid),build(now*2+1,mid+1,r);
		upd(now); 
	}
	inline pair<int,int> qmn(int now,int l,int r)
	{
		if(t[now].l==l&&t[now].r==r) return t[now].mn;
		if(t[now*2].r>=r) return qmn(now*2,l,r);
		else if(t[now*2+1].l<=l) return qmn(now*2+1,l,r);
		else return min(qmn(now*2,l,t[now*2].r),qmn(now*2+1,t[now*2+1].l,r)); 
	}
	inline pair<int,int> qmx(int now,int l,int r)
	{
		if(t[now].l==l&&t[now].r==r) return t[now].mx;
		if(t[now*2].r>=r) return qmx(now*2,l,r);
		else if(t[now*2+1].l<=l) return qmx(now*2+1,l,r);
		else return max(qmx(now*2,l,t[now*2].r),qmx(now*2+1,t[now*2+1].l,r)); 
	}
}TT;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			mx[i]=mn[i]=n+1;
		}
		TT.build(1,1,n);
		ssz=0;
		for(int i=1;i<=n;i++)
		{
			while(ssz&&a[s[ssz]]<a[i]) mx[s[ssz]]=i,--ssz;
			s[++ssz]=i;
		}
		ssz=0;
		for(int i=1;i<=n;i++)
		{
			while(ssz&&a[s[ssz]]>a[i]) mn[s[ssz]]=i,--ssz;
			s[++ssz]=i;
		}
		int now=1;
		int ans=0;
		while(now!=n)
		{
			if(a[now+1]>a[now])
			{
				pair <int,int> mx=TT.qmx(1,now+1,mn[now]-1);
			/*	for(int j=now+1;j<mn[now];j++)
					mx=max(mx,{a[j],j});*/
				now=mx.second;
			}
			else
			{
				pair <int,int> mn=TT.qmn(1,now+1,mx[now]-1);
			//	for(int j=now+1;j<mx[now];j++)
			//		mn=min(mn,{a[j],j});
				now=mn.second;
			}
			++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}