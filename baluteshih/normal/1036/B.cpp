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
	ll n,m,k,q,x,y,ans,tmp;
	cin >> q;
	while(q--)
	{
		cin >> n >> m >> k;
		if(max(n,m)>k)
		{
			cout << "-1\n";
			continue;
		}
		if((n+k)%2==1) x=k-1;
		else x=k;
		if((m+k)%2==1) y=k-1;
		else y=k;
		ans=min(x,y),tmp=min(k-x,k-y);
		if(tmp%2==1) --ans;
		cout << ans << "\n";
	}
}