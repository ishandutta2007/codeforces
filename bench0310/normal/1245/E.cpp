#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

void ini()
{
    v.push_back({0,0});
    int dir=1;
    pair<int,int> now={0,0};
    while(now!=make_pair(9,0))
    {
        if(now.second+dir==10)
        {
            now.first++;
            dir=-1;
        }
        else if(now.second+dir==-1)
        {
            now.first++;
            dir=1;
        }
        else now.second+=dir;
        v.push_back(now);
    }
}

int main()
{
    ini();
    double dp[10][10];
    int h[10][10];
    for(int o=0;o<10;o++) for(int i=0;i<10;i++) cin >> h[o][i];
    dp[0][0]=0;
    for(int i=1;i<=6;i++) dp[0][i]=6;
    for(int i=7;i<(int)v.size();i++)
    {
        int a=v[i].first;
        int b=v[i].second;
        dp[a][b]=0;
        for(int j=1;j<=6;j++)
        {
            int c=v[i-j].first;
            int d=v[i-j].second;
            dp[a][b]+=min(dp[c][d],dp[c-h[c][d]][d]);
        }
        dp[a][b]=(dp[a][b]/6.0);
        dp[a][b]+=1.0;
    }
    cout << fixed << setprecision(9) << dp[9][0] << endl;
    return 0;
}