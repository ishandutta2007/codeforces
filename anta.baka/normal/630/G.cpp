#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[501][6][4][6][4];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<=5; i++)
        for(int j=0; j<=3; j++)
            dp[1][i][j][i][j]=1;

    for(int i=2; i<=n; i++)
        for(int j=0; j<=5; j++)
            for(int k=0; k<=3; k++)
                for(int jj=0; jj<=j; jj++)
                    for(int kk=0; kk<=3; kk++)
                        for(int jjj=0; jj+jjj<=j; jjj++)
                            for(int kkk=0; kk+kkk<=k; kkk++)
                                dp[i][j][k][jj][kk]+=dp[i-1][j-jj][k-kk][jjj][kkk];

    unsigned long long ans=0;
    for(int i=0; i<=5; i++)
        for(int j=0; j<=3; j++)
            ans+=dp[n][5][3][i][j];
    cout<<ans;
    return 0;
}