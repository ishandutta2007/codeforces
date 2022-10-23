#include<iostream>
#include<string>

using namespace std;

const int N = 1e6+4;
int last[2*N];
int b[N];
int dp[N];

int main()
{
    int ans = 0,cnt = 0,n;
    string s;
    cin>>s;
    n = s.size();
    int u = 0;
    for(int i=1;i<=n;++i)
    {
        u += s[i-1]=='('?+1:-1;
        b[i] = u;
    }
    for(int i=0;i<=2e6;++i)
        last[i] = -1;
    for(int i=n;i>=1;--i)
    {
        int v = b[i-1] + 1000000;
        if(last[v]!=-1 && s[i-1]=='(')
        {   
            if(last[v]-i+1+dp[last[v]+1]>ans)
                cnt = 1,ans = last[v]-i+1+dp[last[v]+1];
            else if(last[v]-i + 1 + dp[last[v]+1] == ans)
                ++cnt;
            dp[i] = last[v]-i+1+dp[last[v]+1];
        }   
        last[b[i] + 1000000] = i;
    }
    if(ans == 0)
        cnt = 1;
    cout<<ans<<" "<<cnt;
}