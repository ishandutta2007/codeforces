#include"bits/stdc++.h"
using namespace std;
int ans[3][3][50][50];
int c[4][4];
int main()
{
    c[0][0]=c[0][1]=c[0][2]=c[0][3]=1;
    c[1][1]=1;c[1][2]=2;c[1][3]=3;
    c[2][2]=1;c[2][3]=3;
    c[3][3]=1;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)
    {
        int k0=max(i,j)+1;
        for(int k=k0;k<4;k++)
        {
            for(int l=0;l<k-i;l++)for(int r=0;r<k-j;r++)
            {
                ans[i][j][3+l+r][1]+=c[l][k-i-1]*c[r][k-j-1];
            }
        }
    }
    for(int lon=3;lon<=21;lon++)for(int l1=3;l1<=7&&lon-l1>=0;l1++)for(int k=2;k<=10;k++)
    {
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)
        {
            for(int t=0;t<3;t++)
            {
                    ans[i][j][lon-1][k]+=ans[i][t][lon-l1][k-1]*ans[t][j][l1][1];
            }
        }
    }//cout<<ans[0][0][5][2];
    int n,t;
    cin>>n>>t;
    //for(n=3;n<=20;n++)for(t=1;t<=10;t++)
    {//cout<<n<<" "<<t<<endl;
        int anss=0;
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)anss+=ans[i][j][n][t];
        cout<<anss<<endl;
    }
    return 0;
}