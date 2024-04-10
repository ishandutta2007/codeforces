#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s,arr="BGR",out;

int main()
{jizz
	int n,ans=1e9,tmp;
	cin >> n >> s;
	do
	{
		tmp=0;
		for(int i=0;i<n;++i)
			if(s[i]!=arr[i%3]) ++tmp;
		if(ans>tmp) ans=tmp,out=arr;
	}while(next_permutation(ALL(arr)));
	cout << ans << "\n";
	for(int i=0;i<n;++i)
		cout << out[i%3];
	ET;
}