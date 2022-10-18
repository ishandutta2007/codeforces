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
	ll a,b,c;
	cin >> a >> b >> c;
	if(b>=a+1&&c>=a+2)
		cout << a+a+1+a+2 << "\n";
	else if(a>=b-1&&c>=b+1)
		cout << b-1+b+b+1 << "\n";
	else
		cout << c-2+c-1+c << "\n";
}