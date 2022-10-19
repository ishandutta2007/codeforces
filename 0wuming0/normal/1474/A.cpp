#include"bits/stdc++.h"
using namespace std;
char s[100005];
char ans[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s",s);
        ans[0]='1';
        for(int i=1;i<n;i++)
        {
            if(ans[i-1]+s[i-1]==s[i]+'1')ans[i]='0';
            else ans[i]='1';
        }
        ans[n]=0;
        printf("%s\n",ans);
    }
    return 0;
}