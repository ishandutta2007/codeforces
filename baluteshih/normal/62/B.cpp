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

string s,a;
vector<ll> pl[26];
const ll INF=1e9;

int main()
{jizz
	ll n,k,ans;
	cin >> n >> k >> s;
	for(int i=0;i<k;++i)
		pl[s[i]-'a'].pb(i);
	while(n--)
	{
		cin >> a,ans=0;
		for(int i=0;i<a.size();++i)
			if(pl[a[i]-'a'].empty()) ans+=a.size();
			else
			{
				ll tmp=INF;
				auto p=lower_bound(ALL(pl[a[i]-'a']),i);
				if(p!=pl[a[i]-'a'].end()) tmp=*p-i;
				if(p!=pl[a[i]-'a'].begin()) --p,tmp=min(tmp,i-*p);
				ans+=tmp;
			}
		cout << ans << "\n";
	}
}