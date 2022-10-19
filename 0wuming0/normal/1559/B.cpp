#include"bits/stdc++.h"
using namespace std;
char s[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='?')
            {
                for(int j=i+1;j<n;j++)if(s[j]=='?')
                {
                    if(s[j-1]=='R')s[j]='B';
                    else s[j]='R';
                }
                for(int j=i-1;j>=0;j--)if(s[j]=='?')
                {
                    if(s[j+1]=='R')s[j]='B';
                    else s[j]='R';
                }
                break;
            }
            if(i==n-1)
            {
                for(int j=0;j<n;j++)if(j%2)s[j]='R';else s[j]='B';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}