#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1020;
char cn[V][V];
int K;
int nu[120];
int main()
{
    while(~scanf("%d",&K))
    {
        int n=2;
        int t=0;
        while(K)
        {
            nu[t++]=K%2;
            K/=2;
        }
        for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
        cn[i][j]='N';
        for(int i=t-1;i>=0;i--)
        if(nu[i]==1)
        {
            int s=0;
            for(int j=i;j<t-1;j++)
            {
                cn[s][n]=cn[n][s]='Y';
                s=n++;
            }
            if(i==t-1&&i!=0)
            {
                cn[s][n]=cn[s][n+1]='Y';
                cn[n][s]=cn[n+1][s]='Y';
                for(int j=0;j<i-1;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        for(int l=0;l<2;l++)
                        {
                            int u=n+k;
                            int v=n+l+2;
                            cn[u][v]=cn[v][u]='Y';
                        }
                    }
                    n+=2;
                }
                cn[1][n]=cn[1][n+1]='Y';
                cn[n][1]=cn[n+1][1]='Y';
                n+=2;
            }
            else if(i!=0)
            {
                int m=(t-i)*2;
                cn[s][m]=cn[s][m+1]='Y';
                cn[m][s]=cn[m+1][s]='Y';
            }
            else
            {
                cn[1][s]=cn[s][1]='Y';
            }
        }
        printf("%d\n",n);
        for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++)
        printf("%c",cn[i][j]);
    }
}