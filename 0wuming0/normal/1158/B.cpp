#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    if(n%2==0&&n-2==m)s[--n]='0',m--;
    for(int i=0;i<n;i++)s[i]='1';
    int mod=(n-m)/2+1;
    int a=(n-m)/2,b=(n+m)/2-1;
    for(int i=a;i<n;i+=mod)s[i]='0';
    for(int i=b;i>=0;i-=mod)s[i]='0';
    printf("%s\n",s);
    return 0;
}