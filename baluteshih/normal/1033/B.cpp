#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{jizz
	ll a,b,t,flag;
	cin >> t;
	while(t--)
	{
		cin >> a >> b,flag=0;
		for(ll i=2;i*i<=a+b&&!flag;++i)
			if((a+b)%i==0) flag=1;
		if(a-b>1) flag=1;
		if(flag) cout << "NO\n";
		else cout << "YES\n";
	}
}