#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int arr[20];

pii solve(int l,int r)
{
	if(l==r) return MP(l,r);
	int flag=1;
	for(int i=l+1;i<=r;++i)
		if(arr[i-1]>arr[i]) flag=0;
	if(flag) return MP(l,r);
	int m=l+r>>1;
	pii a,b;
	a=solve(l,m),b=solve(m+1,r);
	if(a.S-a.F>b.S-b.F) return a;
	return b;
}

int main()
{jizz
	int n;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	auto p=solve(0,n-1);
	cout << p.S-p.F+1 << "\n";
}