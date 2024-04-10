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

int main()
{jizz
	ll n,m,i,l;
	cin >> n >> m;
	if(m==0)
		return cout << n << " " << n << "\n",0;
	if(m>=(n+1)/2) cout << "0 ";
	else cout << n-m*2 << " ";
	for(i=1;i*(i-1)/2<m;++i);
	cout << n-i << "\n";
}