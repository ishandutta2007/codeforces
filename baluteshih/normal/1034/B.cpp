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
	ll n,m,ans[6]={0,1,2,3,2,1};
	cin >> n >> m;
	if(n>m) swap(n,m);
	if(n==1)
		return cout << m-ans[m%6] << "\n",0;
	if(n==2)
		return cout << 2*m-(m==2||m==3||m==7)*2-(m==2)*2 << "\n",0;
	cout << n*m-n*m%2 << "\n";
}