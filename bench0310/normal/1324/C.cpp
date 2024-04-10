#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[200005];
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        s[n]='R';
        int idx=-1;
        int res=0;
        for(int i=0;i<=n;i++)
        {
            if(s[i]=='R')
            {
                res=max(res,i-idx);
                idx=i;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}