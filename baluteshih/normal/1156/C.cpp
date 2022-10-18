#pragma GCC optimize("O3")
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

int arr[200005];

int main()
{jizz
	int n,z,l,r;
	cin >> n >> z,l=0,r=n/2;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	sort(arr+1,arr+n+1);
	while(l<r)
	{
		int m=(l+r)/2+1,i,j;
		for(i=1,j=m+1;i<=m;++i,++j)
			while(j<=n&&arr[j]-arr[i]<z) ++j;
		if(j<=n+1) l=m;
		else r=m-1;
	}
	cout << l << "\n";
}