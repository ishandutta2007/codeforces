#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> x={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};

int solve(string s,int val)
{
    string t=x[val];
    bool ok=1;
    int cnt=0;
    for(int i=0;i<7;i++)
    {
        if(s[i]=='1'&&t[i]=='0') ok=0;
        if(s[i]=='0'&&t[i]=='1') cnt++;
    }
    if(ok) return cnt;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<vector<bool>>> dp(n+2,vector<vector<bool>>(k+1,vector<bool>(10,0)));
    for(int j=0;j<10;j++) dp[n+1][0][j]=1;
    vector<vector<int>> val(n+1,vector<int>(10));
    for(int o=1;o<=n;o++) for(int j=0;j<10;j++) val[o][j]=solve(v[o],j);
    for(int o=n;o>=1;o--)
    {
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<10;j++)
            {
                int now=val[o][j];
                if(now==-1) continue;
                if(i-now<0) continue;
                bool ok=0;
                for(int a=0;a<10;a++) ok|=(dp[o+1][i-now][a]);
                dp[o][i][j]=ok;
            }
        }
    }
    bool ok=0;
    for(int j=0;j<10;j++) ok|=dp[1][k][j];
    if(ok)
    {
        string res;
        for(int o=1;o<=n;o++)
        {
            for(int j=9;j>=0;j--)
            {
                if(dp[o][k][j]==1)
                {
                    res+=(j+'0');
                    k-=val[o][j];
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    else printf("-1\n");
    return 0;
}