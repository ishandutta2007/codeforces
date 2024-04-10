#include"bits/stdc++.h"
using namespace std;
char s[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cin>>s;
        int num=0,ans=1e9;
        for(int i=0;i<k;i++)if(s[i]=='W')num++;
        for(int i=k;i<=n;i++)
        {
            ans=min(ans,num);
            if(i==n)break;
            if(s[i]=='W')num++;
            if(s[i-k]=='W')num--;
        }
        cout<<ans<<endl;
    }
    return 0;
}