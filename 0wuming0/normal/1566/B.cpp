#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        int i,j,k;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')break;
        }
        if(i==n)
        {
            printf("0\n");
            continue;
        }
        for(j=n-1;;j--)
        {
            if(s[j]=='0')break;
        }
        for(k=i;k<=j;k++)
        {
            if(s[k]=='1')break;
        }
        if(k==j+1)printf("1\n");
        else printf("2\n");
    }
    return 0;
}