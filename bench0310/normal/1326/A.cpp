#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            printf("-1\n");
            continue;
        }
        int sum=0;
        char s[n+1];
        s[n]='\0';
        for(int i=0;i<n-1;i++)
        {
            s[i]='2';
            sum+=2;
        }
        s[n-1]='3';
        sum+=3;
        if((sum%3)==0) s[n-2]='4';
        printf("%s\n",s);
    }
    return 0;
}