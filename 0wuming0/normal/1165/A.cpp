#include"bits/stdc++.h"
using namespace std;
char s[200005];
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    cin>>s;
    if(s[n-y-1]=='0')s[n-y-1]='1';
    else s[n-y-1]='0';
    int ans=0;
    for(int i=max(0,n-x-1)+1;i<n;i++)
    {
        ans+=s[i]-'0';
    }
    cout<<ans<<endl;
    return 0;
}