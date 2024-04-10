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

int arr[1001];
bitset<1001> vis;

int main()
{jizz
	int n;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1,j;i<=n;++i)
	{
		vis.reset();
		for(j=i;!vis[j];j=arr[j])
			vis[j]=1;
		cout << j << " ";
	}
	ET;
}