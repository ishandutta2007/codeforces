#include"bits/stdc++.h"
using namespace std;
int mod=1e9+7;
char s[2005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int num=0,ans=1;
        while(n--)
        {
            scanf("%s",s);
            for(int i=0;i<m;i++)if(s[i]=='0')num=1;
            else ans=ans*2%mod;
        }
        if(num==0)ans--;
        cout<<ans<<endl;
    }
    return 0;
}