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

int arr[1005];
vector<int> v;

int main()
{jizz
	int n,flag;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=n;i>0;--i)
		arr[i]-=arr[i-1];
	for(int i=1;i<=n;++i)
	{
		flag=1;
		for(int a=i+1,b=1;a<=n&&flag;++a,b=b%i+1)
			if(arr[a]!=arr[b]) flag=0;
		if(flag) v.pb(i);
	}
	cout << v.size() << "\n";
	for(auto i:v)
		cout << i << " ";
	ET;
}