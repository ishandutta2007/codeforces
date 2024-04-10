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

const int MAXC=15000000;
int arr[300000],in[15000001],prime[15000001];
vector<int> p;

int main()
{jizz
	int n,g=0;
	cin >> n;
	for(int i=2;i<=MAXC;++i)
	{
		if(!prime[i]) p.pb(i);
		for(int j:p)
		{
			if(i*j>MAXC) break;
			prime[i*j]=j;
			if(i%j==0) break;
		}
	}
	for(int i=0;i<n;++i)
		cin >> arr[i],g=__gcd(g,arr[i]);
	for(int i=0;i<n;++i)
	{
		arr[i]/=g;
		for(int t=prime[arr[i]];t;t=prime[arr[i]])
			for(++in[t];arr[i]%t==0;arr[i]/=t);
		if(arr[i]>1) ++in[arr[i]];
	}
	g=*max_element(in+2,in+MAXC);
	if(g==0) cout << "-1\n";
	else cout << n-g << "\n"; 
	
}