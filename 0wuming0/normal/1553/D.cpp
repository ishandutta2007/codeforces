#include"bits/stdc++.h"
using namespace std;
char s[100005],t[100005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s%s",s,t);
        int n=strlen(s),m=strlen(t);
        int i=0,j=0;
        if(n+m&1)i++;
        for(;i<n;i+=2)
        {
            if(s[i]==t[j])
            {
                i--;
                j++;
            }
            if(j==m)break;
        }
        if(j==m)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}