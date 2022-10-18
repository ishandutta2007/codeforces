#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int pl[200005];

int main()
{jizz
	int l=0,r=-1,q,x;
	char c;
	cin >> q;
	while(q--)
	{
		cin >> c >> x;
		if(c=='L')
			pl[x]=--l;
		else if(c=='R')
			pl[x]=++r;
		else
			cout << min(pl[x]-l,r-pl[x]) << "\n";
	}
}