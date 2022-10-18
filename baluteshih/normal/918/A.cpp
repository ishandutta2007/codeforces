#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset> 
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;

bool vis[10000];
int dp[1000];

int main()
{
	int n,i;
	for(dp[0]=1,dp[1]=1,i=2,vis[1]=1;dp[i-1]<=1000;i++)
		dp[i]=dp[i-1]+dp[i-2],vis[dp[i]]=1;
	cin >> n;
	for(i=1;i<=n;i++)
		if(vis[i]) cout << "O";
		else cout << "o";
	cout << "\n";
}