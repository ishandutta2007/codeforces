#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll L[100000],R[100000];

int main()
{jizz
	ll n,ans,a,b;
	cin >> n,ans=n,a=b=n-1;
	for(int i=0;i<n;++i)
		cin >> L[i] >> R[i];
	sort(L,L+n),sort(R,R+n);
	for(int i=0;i<n;++i)
		ans+=max(L[i],R[i]);
	cout << ans << "\n";
}