#include"bits/stdc++.h"
using namespace std;
char s[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        int ans=0;
        for(int i=0;i<n;i++)if(s[i]!='0')ans+=s[i]-'0'+1;
        if(s[n-1]!='0')ans--;
        cout<<ans<<endl;
    }
    return 0;
}