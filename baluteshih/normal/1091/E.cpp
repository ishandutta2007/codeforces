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

ll deg[500005],calm[500005],sum[500005];
vector<ll> ans;
priority_queue<ll> expect;
stack<pll> st;

bool yee(ll a,ll b)
{
	return a>b;
}

int main()
{jizz
	ll n,d=0,ed=1e9,ssss=0,flag=0;
	cin >> n;
	for(ll i=1;i<=n;++i)
		cin >> deg[i],ssss+=deg[i];
	deg[n+1]=n;
	sort(deg+1,deg+n+2,yee);
	for(ll i=1;i<=n+1;++i)
		sum[i]=deg[i]+sum[i-1];
	for(ll i=1,t=n+1;i<=n+1;++i)
	{
		while(t>0&&deg[t]<=i) --t;
		if(t>i) calm[i]=i*(i-1)+sum[n+1]-sum[t]+(t-i)*i;
		else calm[i]=i*(i-1)+sum[n+1]-sum[t];
		if(sum[i]>calm[i]) expect.push(sum[i]-calm[i]);
	}
	//DB(sum,1,n+2)
	//DB(calm,1,n+2)
	for(ll i=1,j=2;i<=n+1;i=j-1)
	{
		while(deg[i]!=deg[i+1])
		{
			if(expect.empty()) ans.pb(deg[i]);
			--deg[i],++d;
			while(!st.empty()&&deg[i]<=st.top().F)
				ed=min(ed,(calm[st.top().F]-st.top().S)+d),st.pop();
			if(d>ed) goto output;
			while(!expect.empty()&&d>=expect.top())
				expect.pop();
		}
		while(j<=n+2&&deg[j]==deg[i])
			++j;
		for(ll x=i;x<j-1;++x)
			st.push(MP(x,sum[x]-d));
		while(!st.empty()&&deg[i]<=st.top().F)
			ed=min(ed,(calm[st.top().F]-st.top().S)+d),st.pop();
		if(d>ed) goto output;
	}
	if(expect.empty()) ans.pb(0);
	//cout << "live\n";
	output:
		sort(ALL(ans)),ans.resize(unique(ALL(ans))-ans.begin());
		//for(ll i:ans)
		//	cout << i << " ";
		//ET;
		for(ll i:ans)
			if((i+ssss)&1^1) cout << i << " ",flag=1;
		if(!flag) cout << "-1\n";
		ET;
}