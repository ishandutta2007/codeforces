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

pii a,b;

int main()
{jizz
	int q;
	cin >> q;
	while(q--)
	{
		cin >> a.F >> a.S >> b.F >> b.S;
		if(a<b) cout << a.F << " " << b.F+1 << "\n";
		else cout << a.F+1 << " " << b.F << "\n";
	}
}