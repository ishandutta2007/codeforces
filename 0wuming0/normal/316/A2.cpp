#include"bits/stdc++.h"
using namespace std;
char s[100005];
int a[500];
int main()
{
    long long ans=1;
    scanf("%s",s);
    int n=strlen(s);
    int qq=0;
    if(s[0]=='?')ans=9;
    int now=10;
    if(s[0]>='A'&&s[0]<='J')
    {
        a[s[0]]=9;
        now--;
    }
    for(int i=1;s[i];i++)
    {
        if(s[i]=='?')qq++;
        if(s[i]>='A'&&s[i]<='J'&&a[s[i]]==0)
        {
            a[s[i]]=now;
            now--;
        }
    }
    for(int i=0;i<500;i++)
    {
        if(a[i])ans=ans*a[i];
    }
    cout<<ans;
    for(int i=0;i<qq;i++)putchar('0');
    return 0;
}