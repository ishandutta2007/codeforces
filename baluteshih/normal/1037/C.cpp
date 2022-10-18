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

bitset<1000000> a,b;

int main()
{jizz
	int n,ans=0;
	cin >> n >> a >> b;
	for(int i=0;i<n-1;)
		if((a[i]^b[i]) && (a[i+1]^b[i+1]) && (a[i]^a[i+1])) ++ans,a[i+1]=1^a[i+1],i+=2;
		else if(a[i]^b[i]) ++ans,++i;
		else ++i;
	if(a[n-1]^b[n-1]) ++ans;
	cout << ans << "\n";
}