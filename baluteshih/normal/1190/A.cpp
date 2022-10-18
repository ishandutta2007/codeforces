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

ll arr[100005],cnt[100005];

int main()
{jizz
	ll n,m,k,nw=0,done=0,sub=0;
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i)
		cin >> arr[i];
	for(int i=1;i<=m;++i)
	{
		ll x=(arr[i]-sub)-nw;
		if(x<=0) cnt[i]=cnt[done];
		else if(sub+x>=i)
			cnt[i]=cnt[i-1]+1,done=i,sub=i-1,nw=(((arr[i]-sub)-1)/k+1)*k;
		else
			cnt[i]=cnt[sub+x]+1;
	}
	cout << cnt[m] << "\n";
}