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
        char s[n+1];
        scanf("%s",s);
        int res=n;
        for(int i=0;i<n;i++) if(s[i]=='1') res=max(res,2*max(i+1,n-i));
        printf("%d\n",res);
    }
    return 0;
}