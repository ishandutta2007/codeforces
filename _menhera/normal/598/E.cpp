#include<bits/stdc++.h>
using namespace std;

int DP[31][31][51];

int main()
{
    memset(DP, 0x3f, sizeof DP);
    for(int a=1; a<=30; ++a)
    {
        for(int b=1; b<=30; ++b)
        {
            DP[a][b][0] = 0;
            if(a*b <= 50) DP[a][b][a*b] = 0;
            for(int k=1; k<=min(a*b-1, 50); ++k)
            {
                for(int i=1; i<=a-1; ++i)
                    for(int j=0; j<=k; ++j)
                        DP[a][b][k] = min(DP[a][b][k],
                            DP[i][b][j] + DP[a-i][b][k-j] + b*b);
                for(int i=1; i<=b-1; ++i)
                    for(int j=0; j<=k; ++j)
                        DP[a][b][k] = min(DP[a][b][k],
                            DP[a][i][j] + DP[a][b-i][k-j] + a*a);
            }
        }
    }
    int T; scanf("%d", &T);
    while(T--)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", DP[a][b][c]);
    }
}