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

ll n,arr[1005];

int main()
{jizz
	ll n,h,tmp;
	cin >> n >> h;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<=n;++i)
	{
		sort(arr+1,arr+i+1),tmp=0;
		for(int j=i;j>0;j-=2)
			tmp+=arr[j];
		if(tmp>h)
			return cout << i-1 << "\n",0;
	}
	cout << n << "\n";
}