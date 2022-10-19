#include"bits/stdc++.h"
using namespace std;
char s[100005];
char ans[200005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>s;
        if(n==1)
        {
            cout<<s[0]<<s[0]<<endl;
            continue;
        }
        if(s[0]==s[1])
        {
            cout<<s[0]<<s[0]<<endl;
            continue;
        }
        int k=n-1;
        for(int i=0;i<=n-2;i++)if(s[i]<s[i+1])
        {
            k=i;
            break;
        }
        nn=0;
        for(int i=0;i<=k;i++)ans[nn++]=s[i];
        for(int i=k;i>=0;i--)ans[nn++]=s[i];
        ans[nn]=0;
        cout<<ans<<endl;
    }
    return 0;
}