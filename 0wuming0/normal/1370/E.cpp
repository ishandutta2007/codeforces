#include"bits/stdc++.h"
using namespace std;
char s[1000006];
char t[1000006];
int main()
{
    int n;
    cin>>n;
    scanf("%s%s",s,t);
    int ans=0,check=0,a=0,b=0;
    for(int i=0;i<n;i++)
    {
        check+=s[i]-t[i];
        if(s[i]!=t[i])
        {
            if(s[i]=='1')a++,b=max(0,b-1);
            else b++,a=max(0,a-1);
        }
        ans=max(ans,a+b);
    }
    if(check)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}