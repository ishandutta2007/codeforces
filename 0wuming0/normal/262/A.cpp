#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t,k;
    cin>>t>>k;
    int ans=0;
    while(t--)
    {
        char s[100];
        scanf("%s",s);
        int num=0;
        for(int i=0;s[i];i++)if(s[i]=='4'||s[i]=='7')num++;
        if(num<=k)ans++;
    }cout<<ans<<endl;
    return 0;
}