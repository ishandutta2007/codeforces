#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int dp[100005],arr[100005],pl[100005];

int main()
{jizz
	int n;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i],pl[arr[i]]=i;
	dp[n]=0;
	for(int i=n-1;i>0;--i)
	{
		for(int j=i+pl[i];j<n;j+=i)
			if(arr[j]>i) dp[i]|=dp[arr[j]]^1;
		for(int j=pl[i]-i;j>=0;j-=i)
			if(arr[j]>i) dp[i]|=dp[arr[j]]^1;
	}
	for(int i=0;i<n;++i)
		if(dp[arr[i]]) cout << 'A';
		else cout << 'B';
	ET;
}