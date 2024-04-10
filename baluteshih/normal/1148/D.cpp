#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<pll> L,R;

bool yee(pll a,pll b)
{
	return a.F>b.F;
}

int main()
{jizz
	ll n,a,b;
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		cin >> a >> b;
		if(a<b)
			L.pb(MP(a,i));
		else 
			R.pb(MP(a,i));
	}
	sort(ALL(L),yee),sort(ALL(R));
	if(L.size()>R.size())
	{
		cout << L.size() << "\n";
		for(auto i:L)
			cout << i.S << " ";
		ET;
	}
	else
	{
		cout << R.size() << "\n";
		for(auto i:R)
			cout << i.S << " ";
		ET;
	}
}