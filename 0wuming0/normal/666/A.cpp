#include"bits/stdc++.h"
using namespace std;
int dp[2][10005];
char s[10005];
int main()
{
    cin>>s;
    int n=strlen(s);
    dp[0][n-2]=1;
    dp[1][n-3]=1;
    for(int i=n-4;i>=0;i--)
    {
        if(dp[1][i+2]==1||(dp[0][i+2]==1&&(s[i]!=s[i+2]||s[i+1]!=s[i+3])))dp[0][i]=1;
        if(dp[0][i+3]==1||(dp[1][i+3]==1&&(s[i]!=s[i+3]||s[i+1]!=s[i+4]||s[i+2]!=s[i+5])))dp[1][i]=1;
    }
    set<string>ans;
    for(int i=5;i<n;i++)
    {
        if(dp[0][i])
        {
            string ss;
            ss+=s[i];
            ss+=s[i+1];
            ans.insert(ss);
        }
        if(dp[1][i])
        {
            string ss;
            ss+=s[i];
            ss+=s[i+1];
            ss+=s[i+2];
            ans.insert(ss);
        }
    }
    cout<<ans.size();
    cout<<endl;
    for(auto s:ans)
    {
        cout<<s<<endl;
    }
    return 0;
}