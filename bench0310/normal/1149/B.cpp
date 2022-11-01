#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int,26>> nxt(n+2);
    nxt[n].fill(n);
    nxt[n+1].fill(n);
    for(int i=n-1;i>=0;i--)
    {
        nxt[i]=nxt[i+1];
        nxt[i][s[i]-'a']=i;
    }
    const int N=250;
    vector dp(N+1,vector(N+1,vector(N+1,int(n+1))));
    dp[0][0][0]=0;
    array<int,3> sz={0,0,0};
    array<string,3> t={"","",""};
    auto chmin=[&](int &a,int b){a=min(a,b);};
    while(q--)
    {
        char tp;
        int id;
        cin >> tp >> id;
        id--;
        if(tp=='+')
        {
            char c;
            cin >> c;
            t[id]+=c;
            sz[id]++;
            for(int i=(id==0?sz[0]:0);i<=sz[0];i++)
            {
                for(int j=(id==1?sz[1]:0);j<=sz[1];j++)
                {
                    for(int k=(id==2?sz[2]:0);k<=sz[2];k++)
                    {
                        int &d=dp[i][j][k];
                        d=n+1;
                        if(i>0) chmin(d,nxt[dp[i-1][j][k]][t[0][i-1]-'a']+1);
                        if(j>0) chmin(d,nxt[dp[i][j-1][k]][t[1][j-1]-'a']+1);
                        if(k>0) chmin(d,nxt[dp[i][j][k-1]][t[2][k-1]-'a']+1);
                    }
                }
            }
        }
        else
        {
            t[id].pop_back();
            sz[id]--;
        }
        if(dp[sz[0]][sz[1]][sz[2]]<=n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}