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

ll mp[505][505];

int main()
{jizz
	int n,m,x;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin >> mp[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(cin >> x,x)
				mp[i][j]^=1;
	for(int i=0;i+1<n;++i)
		for(int j=0;j+1<m;++j)
			if(mp[i][j])
				mp[i][j]^=1,mp[i+1][j]^=1,mp[i][j+1]^=1,mp[i+1][j+1]^=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(mp[i][j])
				return cout << "No\n",0;
	cout << "Yes\n";
}