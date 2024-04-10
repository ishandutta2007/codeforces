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

pll arr[1005],arr2[1005];
set<pll> s;

int main()
{jizz
	ll n,flag;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i].F >> arr[i].S;
	for(int i=0;i<n;++i)
		cin >> arr2[i].F >> arr2[i].S,s.insert(arr2[i]);
	for(int i=0;i<n;++i)
	{
		pll tmp=MP(arr[0].F+arr2[i].F,arr[0].S+arr2[i].S);
		flag=1;
		for(int j=1;j<n&&flag;++j)
			if(s.find(MP(tmp.F-arr[j].F,tmp.S-arr[j].S))==s.end()) flag=0;
		if(flag)
			return cout << tmp.F << " " << tmp.S << "\n",0;
	}
}