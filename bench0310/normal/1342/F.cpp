#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> sum((1<<n),0);
        for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) if(i&(1<<j)) sum[i]+=a[j];
        int dp[n+1][1<<n][n];
        array<int,3> u[n+1][1<<n][n];
        const int inf=(1<<30);
        for(int i=0;i<=n;i++) for(int j=0;j<(1<<n);j++) for(int k=0;k<n;k++) {dp[i][j][k]=inf;u[i][j][k].fill(-1);}
        int all=(1<<n)-1;
        dp[0][0][0]=0;
        int lsb[1<<n];
        int msb[1<<n];
        for(int i=1;i<(1<<n);i++)
        {
            for(int j=n-1;j>=0;j--) if(i&(1<<j)) lsb[i]=j;
            for(int j=0;j<n;j++) if(i&(1<<j)) msb[i]=j;
        }
        auto chmin=[&](int &x,int y)->bool{return ((y<x)?(x=y):0);};
        for(int c=0;c<n;c++)
        {
            for(int m=0;m<(1<<n);m++)
            {
                for(int p=0;p<n;p++)
                {
                    if(dp[c][m][p]==inf) continue;
                    for(int s=(m^all);s>0;s=(s-1)&(m^all))
                    {
                        int l=lsb[s&(all^((1<<p)-1))];
                        if(msb[s]>=p&&sum[s]>dp[c][m][p]&&chmin(dp[c+1][m^s][l],sum[s])) u[c+1][m^s][l]={c,m,p};
                    }
                }
            }
        }
        vector<bool> used(n+1,0);
        auto mv=[&](int i,int j)
        {
            int pi=0,pj=0;
            for(int k=1;k<=i;k++) pi+=(used[k]==0);
            for(int k=1;k<=j;k++) pj+=(used[k]==0);
            cout << pi << " " << pj << "\n";
            used[i]=1;
        };
        for(int c=n;c>=1;c--)
        {
            for(int p=0;p<n;p++)
            {
                if(dp[c][all][p]==inf) continue;
                cout << n-c << "\n";
                vector<int> masks;
                int tc=c;
                int tm=all;
                int tp=p;
                while(tc>0)
                {
                    auto &tn=u[tc][tm][tp];
                    masks.push_back(tm^tn[1]);
                    tc=tn[0];
                    tm=tn[1];
                    tp=tn[2];
                }
                reverse(masks.begin(),masks.end());
                int r=-1;
                for(int m:masks)
                {
                    int nr=-1;
                    for(int i=n-1;i>r;i--) if(m&(1<<i)) nr=i;
                    for(int i=0;i<n;i++) if((m&(1<<i))&&i!=nr) mv(i+1,nr+1);
                    r=nr;
                }
                goto done;
            }
        }
        done:;
    }
    return 0;
}