#include"bits/stdc++.h"
using namespace std;
char s[1005];
int ans[1005];
int main()
{
    scanf("%s",s);
    int n;
    n=strlen(s);
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])ans[i]=1;
    }
    if(s[n-1]=='a')ans[n-1]=1;
    for(int i=0;i<n;i++)
    {
        printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}