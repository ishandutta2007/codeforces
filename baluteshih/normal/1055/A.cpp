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

int a[1005],b[1005];

int main()
{jizz
	int n,s;
	cin >> n >> s;
	for(int i=1;i<=n;++i)
		cin >> a[i];
	for(int i=1;i<=n;++i)
		cin >> b[i];
	if(!a[1])
		return cout << "NO\n",0;
	if(a[s])
		return cout << "YES\n",0;
	if(!b[s])
		return cout << "NO\n",0;
	for(int i=s+1;i<=n;++i)
		if(a[i]&&b[i])
			return cout << "YES\n",0;
	cout << "NO\n";
}