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

int boss[500005],cnt[500005];

int finds(int x)
{
	if(x==boss[x]) return x;
	return boss[x]=finds(boss[x]);
}

int main()
{jizz
	int n,m,k,ls,x;
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		boss[i]=i;
	while(m--)
	{
		cin >> k;
		if(k)
			cin >> ls;
		else continue;
		while(--k)
			cin >> x,boss[finds(ls)]=finds(x),ls=x;
	}
	for(int i=1;i<=n;++i)
		++cnt[finds(i)];
	for(int i=1;i<=n;++i)
		cout << cnt[finds(i)] << " \n"[i==n];
}