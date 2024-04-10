#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map<int,int> m;
int arr[120000];

int main()
{jizz
	int n,ans=0;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i],++m[arr[i]];
	for(int i=0;i<n;++i)
		for(int j=0;j<31;++j)
			if(m[(1<<j)-arr[i]]>((1<<j)-arr[i]==arr[i]))
			{
				++ans;
				break;
			}
	cout << n-ans << "\n";
}