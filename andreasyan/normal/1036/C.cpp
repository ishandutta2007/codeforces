#include <bits/stdc++.h>
using namespace std;

int n;
char a[22];
long long dp[22][4][2];
long long qryp()
{
    for (int i = 0;i <= n; ++ i)
        for (int j = 0; j < 4; ++ j)
            for(int k=0;k<2;++k)
                dp[i][j][k]=0;
    dp[0][0][1]=1;
    for (int i=0; i < n;++ i)
    {
        for (int j=0; j<4; ++ j)
        {
            for (int k = 0; k <=9; ++ k)
            {
                if(j<3)
                {
                    if(k==0)
                        dp[i+1][j][0]+=dp[i][j][0];
                    else
                        dp[i+1][j+1][0]+=dp[i][j][0];
                }
                else
                {
                    if(k==0)
                        dp[i+1][j][0]+=dp[i][j][0];
                }
            }
            for(int k=0;k<=9;++k)
            {
                if(j<3)
                {
                    if(k<a[i]-'0')
                    {
                        if(k==0)
                            dp[i+1][j][0]+=dp[i][j][1];
                        else
                            dp[i+1][j+1][0]+=dp[i][j][1];
                    }
                    else if(k==a[i]-'0')
                    {
                        if(k==0)
                            dp[i+1][j][1]+=dp[i][j][1];
                        else
                            dp[i+1][j+1][1]+=dp[i][j][1];
                    }
                }
                else
                {
                    if(k<a[i]-'0')
                    {
                        if(k==0)
                            dp[i+1][j][0]+=dp[i][j][1];
                    }
                    else if(k==a[i]-'0')
                    {
                        if(k==0)
                            dp[i+1][j][1]+=dp[i][j][1];
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int j=0;j<4;++j)
        ans+=(dp[n][j][0]+dp[n][j][1]);
    return ans;
}

long long qry ()
{
    char l[22], r[22];
    cin >> l >> r;
    n=strlen(l);
    for (int i=0;i<n;++i)
        a[i]=l[i];
    long long ansl=qryp();
    n=strlen(r);
    for (int i=0;i<n;++i)
        a[i]=r[i];
    long long ansr=qryp();
    n=strlen(l);
    int z=0;
    for(int i=0;i<n;++i)
    {
        if(l[i]>'0')
            ++z;
    }
    return ansr-ansl+(z<=3);
}

int main()
{
    int tt;
    cin >> tt;
    while (tt --)
    {
        cout << qry () << endl;
    }
    return 0;
}