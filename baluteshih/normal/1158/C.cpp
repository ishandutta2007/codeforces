#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0);
#define ET cout << "\n"
#define F first
#define S second
#define MP make_pair
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

int arr[500005],ans[500005];
vector<int> v;
vector<pii> vv;

int main()
{jizz
	int t,n,flag;
	cin >> t;
	while(t--)
	{
		cin >> n,flag=0,v.clear(),v.pb(n+1),vv.clear();
		for(int i=1;i<=n;++i)
		{
			cin >> arr[i];
			if(i==v.back()) v.pop_back();
			if(!~arr[i]) arr[i]=v.back();
			else if(arr[i]>v.back()) flag=1;
			else if(arr[i]<v.back()) v.pb(arr[i]);
			vv.pb(MP(arr[i],-i));
		}
		if(flag)
		{
			cout << "-1\n";
			continue;
		} 
		sort(ALL(vv));
		for(int i=0;i<vv.size();++i)
			ans[-vv[i].S]=i+1;
		for(int i=1;i<=n;++i)
			cout << ans[i] << " \n"[i==n];
	}
}