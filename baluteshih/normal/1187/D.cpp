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

int a[300005],b[300005],to[300005],bit[300005],n;
vector<int> pl[300005];

void modify(int x,int v)
{
	for(;x<=n;x+=x&-x) bit[x]=max(bit[x],v);
}

int query(int x)
{
	int re=0;
	for(;x;x-=x&-x) re=max(re,bit[x]);
	return re;
}

int main()
{jizz
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<=n;++i)
			pl[i].clear(),bit[i]=0;
		for(int i=1;i<=n;++i)
			cin >> a[i],pl[a[i]].pb(i);
		for(int i=1;i<=n;++i)
			cin >> b[i];
		for(int i=n;i>=1;--i)
			if(pl[b[i]].empty()) goto bye;
			else to[pl[b[i]].back()]=i,pl[b[i]].pop_back();
		for(int i=1;i<=n;++i)
			if(query(a[i])>to[i]) goto bye;
			else modify(a[i],to[i]);
		cout << "YES\n";
		continue;
		bye:
			cout << "NO\n";
	}
}