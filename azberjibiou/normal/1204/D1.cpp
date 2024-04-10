#include <bits/stdc++.h>
using namespace std;
#define gibon     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
char A[2020];
int dp[2020][2], B[2020], dpp[2020][2];
int main()
{
    gibon
    cin >> A;
    int lenA=strlen(A);
    if(A[lenA-1]=='0')
        dp[lenA-1][0]=1, dp[lenA-1][1]=0;
    else
        dp[lenA-1][0]=0, dp[lenA-1][1]=1;
    for(int i=lenA-2;i>=0;i--)
    {
        if(A[i]=='0')
        dp[i][0]=max(dp[i+1][0], dp[i+1][1])+1, dp[i][1]=dp[i+1][1];
        else
        dp[i][0]=dp[i+1][0], dp[i][1]=dp[i+1][1]+1;
    }
    for(int i=lenA-1;i>=0;i--)
    {
        if(A[i]=='0')
        {
            B[i]=0;
            dpp[i][0]=max(dpp[i+1][0], dpp[i+1][1])+1;
            dpp[i][1]=dpp[i+1][1];
        }
        else
        {
            if(dp[i+1][0]==dp[i+1][1])
            {
                if(dpp[i+1][0]==dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
            }
            else if(dp[i+1][0]>dp[i+1][1])
            {
                if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
                else
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
            }
            else
            {
                if(dpp[i+1][0]==dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
                else
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
            }
        }
    }
    for(int i=0;i<lenA;i++)
    {
        cout << B[i];
    }
}