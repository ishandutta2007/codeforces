#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1003;
const long long M=998244353;

int n,k;
long long dp[N][N*2][4];

int t[4][4];
int main()
{
	//freopen("input.txt","r",stdin);
	t[0][0]=0;
	t[0][1]=1;
	t[0][2]=1;
	t[0][3]=1;
	t[1][0]=0;
	t[1][1]=0;
	t[1][2]=2;
	t[1][3]=0;
	t[2][0]=0;
	t[2][1]=2;
	t[2][2]=0;
	t[2][3]=0;
	t[3][0]=1;
	t[3][1]=1;
	t[3][2]=1;
	t[3][3]=0;
	cin>>n>>k;
	dp[1][1][0]=1;
	dp[1][2][1]=1;
	dp[1][2][2]=1;
	dp[1][1][3]=1;
	for(int i=1;i<n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            for(int x=0;x<4;++x)
            {
                for(int y=0;y<4;++y)
                {
                    dp[i+1][j+t[x][y]][y]+=dp[i][j][x];
                    dp[i+1][j+t[x][y]][y]%=M;
                }
            }
        }
    }
    cout<<(((dp[n][k][0]+dp[n][k][1])%M+dp[n][k][2])%M+dp[n][k][3])%M<<endl;
	return 0;
}