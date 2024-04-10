#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
struct qwq
{
	int addi,add1,pos;
};
vector<qwq> v;
bool cmp(qwq x,qwq y)
{
	return x.pos<y.pos;
}
int a[200005],b[200005],ans[200005];
const int inf=2e9;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++) ans[i]=0;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i];
			v.push_back({1,-(a[i]-b[i]),a[i]-b[i]});
			v.push_back({-2,a[i]*2,a[i]});
			v.push_back({1,-(a[i]+b[i]),a[i]+b[i]});
		}
		sort(v.begin(),v.end(),cmp);
		int nw1=0,nwi=0;
		v.push_back({0,0,inf});
		vector<pair<int,int> > s;
		for(int i=0;i<v.size()-1;i++)
		{
			auto t=v[i];
			nw1+=t.add1;
			nwi+=t.addi;
			if(t.pos!=v[i+1].pos) s.push_back({t.pos,nwi*t.pos+nw1});
		}
		for(int i=1;i<=n;i++)
		{
			s.push_back({a[i],-i});
		}
	/*	for(auto t:s)
		{
			cout << t.first << "*" << t.second << "\n"; 
		}*/
		sort(s.begin(),s.end());
		int mx=-1e18,lst=0;
		for(auto t:s)
		{
			mx+=t.first-lst;
			lst=t.first;
			if(t.second>m)
				mx=max(mx,t.second-m);
			if(t.second<0) ans[-t.second]=max(ans[-t.second],mx);
		}
		reverse(s.begin(),s.end());
		mx=-1e18,lst=2e9;
		for(auto t:s)
		{
			mx+=lst-t.first;
			lst=t.first;
			if(t.second>m)
				mx=max(mx,t.second-m);
			if(t.second<0) ans[-t.second]=max(ans[-t.second],mx);
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]<=b[i]) cout << 1;
			else cout << 0;
		}
		cout << "\n";
	}
	return 0;
}