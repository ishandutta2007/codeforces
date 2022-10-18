#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[100005],ans[100005];
vector<int> cnt[100005],fac[100005];

int main()
{jizz
	int n,x,t=1,flag,ct;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i],cnt[arr[i]].pb(i);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			fac[j].pb(i);
	for(int i=0;i<n;++i)
		if(cnt[i].size())
		{
			flag=0;
			for(int j:fac[cnt[i].size()])
				if(n-cnt[i].size()+(cnt[i].size()/j-1)*j==i)
				{
					ct=0;
					for(int k:cnt[i])
					{
						ans[k]=t,++ct;
						if(ct==j) ++t,ct=0;
					}
					flag=1;
					break;
				}
			if(!flag)
				return cout << "Impossible\n",0;
		}
	cout << "Possible\n";
	for(int i=0;i<n;++i)
		cout << ans[i] << " ";
	ET;
}