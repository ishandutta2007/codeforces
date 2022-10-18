#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset> 
#include <map>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;

struct mode
{
	int a,c;
};

int dp[27][101][101];
vector<mode> child[101];

bool get_dp(int k,int i,int j)
{
	if(~dp[k][i][j]) return dp[k][i][j];
	int tmp;
	for(auto x:child[i])
		if(x.c>=k)
		{
			tmp=get_dp(x.c,j,x.a);
			if(!tmp) return dp[k][i][j]=1;
		}
	return dp[k][i][j]=0;
}

int main()
{jizz
	int n,m,a,b,i,j,k;
	char c;
	cin >> n >> m;
	while(m--)
		cin >> a >> b >> c,child[a].pb(mode{b,c-'a'+1});
	for(k=0;k<27;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				dp[k][i][j]=-1;
	for(i=1;i<=n;cout << "\n",i++)
		for(j=1;j<=n;j++)
			if(get_dp(0,i,j)) cout << "A";
			else cout << "B";
}