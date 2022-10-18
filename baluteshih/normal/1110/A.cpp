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
	ll n,k,x,ans=0;
	cin >> n >> k;
	while(--k)
	{
		cin >> x;
		if(n&1) ans^=x&1;
	}
	cin >> x;
	ans^=x&1;
	if(ans) cout << "odd\n";
	else cout << "even\n";
}