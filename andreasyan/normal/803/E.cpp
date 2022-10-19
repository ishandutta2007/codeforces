#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1005;

int n,k;
char a[N];

bool dp[N][N+N];
char p[N][N+N];
pair<int,int> pp[N][N+N];
int main()
{
    cin>>n>>k;
    cin>>a;
    dp[0][k]=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=k+k;++j)
        {
            if(!dp[i][j])continue;
            if(a[i]=='W')
            {
                if(j+1<k+k || (j+1==k+k && i+1==n))
                {
                    dp[i+1][j+1]=true;
                    p[i+1][j+1]='W';
                    pp[i+1][j+1]=m_p(i,j);
                }
            }
            else if(a[i]=='L')
            {
                if(j-1>0 || (j-1==0 && i+1==n))
                {
                    dp[i+1][j-1]=true;
                    p[i+1][j-1]='L';
                    pp[i+1][j-1]=m_p(i,j);
                }
            }
            else if(a[i]=='D')
            {
                dp[i+1][j]=true;
                p[i+1][j]='D';
                pp[i+1][j]=m_p(i,j);
            }
            else
            {
                if(j+1<k+k || (j+1==k+k && i+1==n))
                {
                    dp[i+1][j+1]=true;
                    p[i+1][j+1]='W';
                    pp[i+1][j+1]=m_p(i,j);
                }
                if(j-1>0 || (j-1==0 && i+1==n))
                {
                    dp[i+1][j-1]=true;
                    p[i+1][j-1]='L';
                    pp[i+1][j-1]=m_p(i,j);
                }
                dp[i+1][j]=true;
                p[i+1][j]='D';
                pp[i+1][j]=m_p(i,j);
            }
        }
    }
    string ans;
    if(dp[n][k+k])
    {
        for(int i=n,j=k+k;ans.size()<n;)
        {
            ans+=p[i][j];
            int ii=i;
            int jj=j;
            i=pp[ii][jj].first;
            j=pp[ii][jj].second;
        }
    }
    else if(dp[n][0])
    {
        for(int i=n,j=0;ans.size()<n;)
        {
            ans+=p[i][j];
            int ii=i;
            int jj=j;
            i=pp[ii][jj].first;
            j=pp[ii][jj].second;
        }
    }
    else
        ans="ON";
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}