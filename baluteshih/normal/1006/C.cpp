#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll num[200000];

int main()
{jizz
	ll n,l,r,la=0,ra=0,mx=0;
	cin >> n,l=0,r=n-1;
	for(int i=0;i<n;++i)
		cin >> num[i];
	while(l<=r)
	{
		if(la+num[l]<=ra+num[r]) la+=num[l],++l;
		else ra+=num[r],--r;
		if(la==ra) mx=la;
	}
	cout << mx << "\n";
}