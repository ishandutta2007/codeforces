#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int N=2002,M=1000000007;
void ad(int& x,int y)
{
	x=x+y;
	x%=M;
}

int m,d;
int stg(string s)
{
    int n=s.size();
	int t=0;
    for(int i=0;i<n;++i)
    {
		int x=s[i]-'0';
		t=(t*10+x)%m;
        if(i%2 && x!=d)
            return 0;
        if(!(i%2) && x==d)
            return 0;
    }
	if(t==0)
		return 1;
	return 0;
}
int f(string s)
{
    int n=s.size();
	int dp[N][N][2];
    for(int i=0;i<=n;++i)for(int j=0;j<m;++j)for(int k=0;k<2;++k)dp[i][j][k]=0;
	dp[0][0][1]=1;
    for(int i=0;i<n;++i)
    {
        int x=s[i]-'0';
        for(int j=0;j<m;++j)
        {
            if(i%2)
            {
                for(int k=d;k<=d;++k)
                {
                    if(k<x)
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][1]);
                    }
                    else if(k==x)
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                        ad(dp[i+1][(j*10+k)%m][1],dp[i][j][1]);
                    }
                    else
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                    }
                }
            }
            else
            {
                for(int k=0;k<=9;++k)
                {
					if(i==0 && k==0)
						continue;
                    if(k==d)
                        continue;
                    if(k<x)
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][1]);
                    }
                    else if(k==x)
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                        ad(dp[i+1][(j*10+k)%m][1],dp[i][j][1]);
                    }
                    else
                    {
                        ad(dp[i+1][(j*10+k)%m][0],dp[i][j][0]);
                    }
                }
            }
        }
    }
    return (dp[n][0][0]+dp[n][0][1])%M;
}

int main()
{
    string a, b;
    cin>>m>>d;
    cin>>a;
    cin>>b;
    cout<<((f(b)-f(a)+M)%M+stg(a))%M<<endl;
    return 0;
}