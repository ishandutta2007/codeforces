#include <bits/stdc++.h>

using namespace std;
const int N=16;
const int mod=1000000007;

vector<int> t(N),g(N);
int dp[4][226][(1<<16)];

int solve(int last,int tleft,int a)
{
    if(tleft<0) return 0;
    if(dp[last][tleft][a]!=-1) return dp[last][tleft][a];
    if(tleft==0)
    {
        dp[last][tleft][a]=1;
        return 1;
    }
    dp[last][tleft][a]=0;
    //cout << "in " << last << " " << tleft << " " << a << endl;
    int b=a;
    int e=0;
    while(b)
    {
        if((b&1)==1&&last!=g[e])
        {
            dp[last][tleft][a]+=solve(g[e],tleft-t[e],a-(1<<e));
            if(dp[last][tleft][a]>=mod) dp[last][tleft][a]%=mod;
        }
        b/=2;
        e++;
    }
    //cout << "out " << dp[last][tleft][a] << endl;
    return dp[last][tleft][a];
}

int main()
{
    for(int o=0;o<4;o++) for(int i=0;i<226;i++) for(int j=0;j<(1<<16);j++) dp[o][i][j]=-1;
	int n,tm;
	cin >> n >> tm;
	for(int i=0;i<n;i++) cin >> t[i] >> g[i];
	printf("%d\n",solve(0,tm,(1<<n)-1));
	return 0;
}