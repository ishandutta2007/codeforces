#include"bits/stdc++.h"
using namespace std;
char s[1005];
char num[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        for(int i=0;s[i];i++)
        {
            num[s[i]]=i;
        }
        scanf("%s",s);
        int ans=0;
        for(int i=1;s[i];i++)
        {
            ans+=abs(num[s[i]]-num[s[i-1]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}