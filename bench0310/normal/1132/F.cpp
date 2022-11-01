#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int dp[500][500];

int solve(int l,int r)
{
    int &res=dp[l][r];
    if(res!=-1) return res;
    if(l>r) return res=0;
    if(l==r) return res=1;
    res=1+solve(l+1,r);
    for(int i=l+1;i<=r;i++)
    {
        if(s[l]==s[i]) res=min(res,solve(l+1,i-1)+solve(i,r));
    }
    return res;
}

int main()
{
    cin >> n >> s;
    memset(dp,-1,sizeof dp);
    cout << solve(0,n-1) << endl;
    return 0;
}