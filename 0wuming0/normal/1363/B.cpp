#include"bits/stdc++.h"
using namespace std;
char s[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int ans=100000;
        scanf("%s",s);
        int num=0,now=0;
        int n=strlen(s);
        for(int i=0;s[i];i++)if(s[i]=='1')num++;
        for(int i=0;s[i];i++)
        {
            ans=min(ans,min(i-now+num-now,n-(i-now+num-now)));
            if(s[i]=='1')now++;
        }
        ans=min(ans,min(n-num,num));
        cout<<ans<<endl;
    }
    return 0;
}