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

int n,arr[300005];

int main()
{jizz
	int n,ans=0,tmp=0;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];
	for(int i=1;i<n;++i)
		if(arr[i]!=arr[0]) ans=i;
	for(int i=n-2;i>=0;--i)
		if(arr[i]!=arr[n-1]) tmp=n-i-1;
	cout << max(ans,tmp) << "\n";
}