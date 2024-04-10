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
	int n,nw=0,x=1,mx,idx,i;
	cin >> n;
	while(2*x<=n)
	{
		mx=n/(2*x);
		for(i=3*x;i<=n&&n/i==mx;i+=x);
		i-=x,mx=n-mx;
		for(;nw<mx;++nw)
			cout << x << " ";
		x=i;
	}
	cout << x << "\n";
}