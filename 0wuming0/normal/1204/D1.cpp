#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100003],n;
char s[100003];
int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=n-2;i>=0;i--)
    {
        if(s[i+1]=='1')a[i]=min(0,a[i+1]+1);
        else a[i]=a[i+1]-1;
    }
    for(int i=0;i<n;i++)
        putchar(a[i]==0?'0':s[i]);
    putchar('\n');
    return 0;
}