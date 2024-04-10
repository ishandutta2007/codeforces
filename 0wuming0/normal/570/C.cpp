#include"bits/stdc++.h"
using namespace std;
char s[300005];
int main()
{
    int n,q;
    cin>>n>>q;
    cin>>s+1;
    int ans=0;
    for(int i=2;s[i];i++)if(s[i-1]=='.'&&s[i]=='.')ans++;
    while(q--)
    {
        int k;
        char c[3];
        scanf("%d%s",&k,c);
        if(s[k]=='.'&&s[k-1]=='.')ans--;
        if(s[k]=='.'&&s[k+1]=='.')ans--;
        s[k]=c[0];
        if(s[k]=='.'&&s[k-1]=='.')ans++;
        if(s[k]=='.'&&s[k+1]=='.')ans++;
        printf("%d\n",ans);
    }
    return 0;
}