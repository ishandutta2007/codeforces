#include"bits/stdc++.h"
using namespace std;
char s[10000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        scanf("%s",s);
        int a0=0,a1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')a0++;
            else a1++;
        }
        int ans=c0*a0+c1*a1;
        ans=min(ans,n*c0+h*a1);
        ans=min(ans,n*c1+h*a0);
        cout<<ans<<endl;
    }
    return 0;
}