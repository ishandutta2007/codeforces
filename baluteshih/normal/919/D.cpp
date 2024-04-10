#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

vector<int> child[300001];
int dp[300001][26],in[300001];
string s;
queue<int> q;

int main()
{jizz
	int n,m,a,b,ans=0;
	cin >> n >> m;
	cin >> s;
	while(m--)
		cin >> a >> b,in[b]++,child[a].pb(b);
	for(int i=1;i<=n;i++)
		if(!in[i]) q.push(i),dp[i][s[i-1]-'a']=1;
	while(!q.empty())
	{
		a=q.front(),q.pop();
		for(int i:child[a])
		{
			in[i]--;
			for(int j=0;j<26;j++)
				dp[i][j]=max(dp[i][j],dp[a][j]);
			dp[i][s[i-1]-'a']=max(dp[i][s[i-1]-'a'],dp[a][s[i-1]-'a']+1);
			if(!in[i]) q.push(i);
		}
	} 
	for(int i=1;i<=n;i++)
	{
		if(in[i])
			return cout << "-1\n",0;
		for(int j=0;j<26;j++)
			ans=max(dp[i][j],ans); 
	}
	cout << ans << "\n";
}