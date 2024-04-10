#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[15][100005],pl[15][100005];

int main()
{jizz
	ll n,m,ans=0,cnt=0,flag;
	cin >> n >> m;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin >> arr[i][j],pl[i][arr[i][j]]=j;
	for(int i=0;i<n;++i)
	{
		flag=1;
		for(int j=1;j<m&&flag;++j)
			if(pl[j][arr[0][i]]-cnt<0||arr[j][pl[j][arr[0][i]]-cnt]!=arr[0][i-cnt]) flag=0;
		if(flag) ++cnt;
		else ans+=cnt*(cnt+1)/2,cnt=1;
	}
	ans+=cnt*(cnt+1)/2;
	cout << ans << "\n";
}