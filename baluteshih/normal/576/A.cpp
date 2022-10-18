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

vector<int> v;
int prime[1005];

int main()
{jizz
	int n;
	cin >> n;
	for(int i=2;i<=n;++i)
		for(int j=i+i;j<=n;j+=i)
			prime[j]=1;
	for(int i=2;i<=n;++i)
		if(!prime[i])
			for(int j=i;j<=n;j*=i)
				v.pb(j);
	cout << v.size() << "\n";
	for(int i:v)
		cout << i << " ";
	ET;
}