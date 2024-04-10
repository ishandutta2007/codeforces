#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[100];
        scanf("%s",s);
        int n=strlen(s);
        if((s[n-1]-'0')%2==0)printf("0\n");
        else if((s[0]-'0')%2==0)printf("1\n");
        else
        {
            bool flag=0;
            for(int i=0;i<n;i++)if((s[i]-'0')%2==0)flag=1;
            if(flag)printf("2\n");
            else printf("-1\n");
        }
    }
    return 0;
}