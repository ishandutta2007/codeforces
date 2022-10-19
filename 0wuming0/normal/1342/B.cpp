#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[105];
        scanf("%s",s);
        int i;
        int n=strlen(s);
        for(i=1;s[i];i++)
        {
            if(s[i]!=s[0])break;
        }
        if(i==n)printf("%s\n",s);
        else
        {
            for(int i=0;i<n;i++)
            printf("01");
            putchar(10);
        }
    }
    return 0;
}