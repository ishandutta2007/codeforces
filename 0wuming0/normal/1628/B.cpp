#include"bits/stdc++.h"
using namespace std;
char s[100005][8];
int dp[26][26];
int dp2[26][26][26];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(int i=0;i<26;i++)for(int j=0;j<26;j++)dp[i][j]=0;
        for(int i=0;i<26;i++)for(int j=0;j<26;j++)for(int k=0;k<26;k++)dp2[i][j][k]=0;
        for(int i=0;i<n;i++)
        {
            int nn=strlen(s[i]);
            if(nn==1)
            {cout<<"YES"<<endl;goto ne;}
            else if(nn==2&&s[i][0]==s[i][1]){cout<<"YES"<<endl;goto ne;}
            else if(nn==3&&s[i][0]==s[i][2]){cout<<"YES"<<endl;goto ne;}
            if(nn==2)dp[s[i][0]-'a'][s[i][1]-'a']=1;
            if(nn==3)
            {
                dp2[s[i][0]-'a'][s[i][1]-'a'][s[i][2]-'a']=1;
                if(dp2[s[i][2]-'a'][s[i][1]-'a'][s[i][0]-'a']==1){cout<<"YES"<<endl;goto ne;}
                if(dp[s[i][0]-'a'][s[i][1]-'a']==0)dp[s[i][0]-'a'][s[i][1]-'a']=2;
            }
            if(dp[s[i][nn-1]-'a'][s[i][nn-2]-'a']==1){cout<<"YES"<<endl;goto ne;}
            if(nn==2&&dp[s[i][nn-1]-'a'][s[i][nn-2]-'a']==2){cout<<"YES"<<endl;goto ne;}
        }
        cout<<"NO"<<endl;
        ne:;
    }
    return 0;
}
/*
10000
1
a
2
abb
ba
*/