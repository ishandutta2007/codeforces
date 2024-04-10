#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pii coff[200000];
int ans[200000];
deque<int> dq;

int main()
{jizz
	int n,m,d,t=0;
	cin >> n >> m >> d;
	for(int i=0;i<n;++i)
		cin >> coff[i].F,coff[i].S=i;
	sort(coff,coff+n);
	for(int i=0;i<n;++i)
	{
		if(!dq.empty() && coff[i].F-coff[dq.front()].F>d)
			ans[coff[i].S]=ans[coff[dq.front()].S],dq.pop_front();
		else
			ans[coff[i].S]=++t;
		dq.pb(i);
	}
	cout << t << "\n";
	for(int i=0;i<n;++i)
		cout << ans[i] << " ";
	ET;
}