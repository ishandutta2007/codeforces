#include <bits/stdc++.h>
using namespace std;
char A[2010101];
int B[2010101], jogun, dp[10];
int main()
{
    cin >> A;
    int len=strlen(A);
    for(int i=0;i<len-1;i++)
    {
        B[i]=(A[i+1]-A[i]+20)%10;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            jogun=0;
            for(int k=0;k<=9;k++)
                dp[k]=1000000;
            for(int k=1;k<=10;k++)
            {
                dp[(k*i)%10]=min(dp[(k*i)%10], k);
            }
            for(int l=1;l<=10;l++)
            {
                for(int k=0;k<=10;k++)
                {
                    dp[(k*i+l*j)%10]=min(dp[(k*i+l*j)%10], k+l);
                }
            }
            int ans=0;
            for(int k=0;k<len-1;k++)
            {
                if(dp[B[k]]==1000000)
                {
                    cout << -1 << " ";
                    jogun=-1;
                    break;
                }
                ans+=dp[B[k]]-1;
            }
            if(jogun==0)
                cout << ans << " ";
        }
        cout << '\n';
    }
}