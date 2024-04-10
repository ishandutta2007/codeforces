#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int cnt=0;
    int sum=0;
    int res=0;
    bool in=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') sum++;
        else sum--;
        if(!in&&sum==-1)
        {
            in=1;
            cnt=1;
        }
        if(in&&sum<0) cnt++;
        if(in&&sum==0)
        {
            res+=cnt;
            in=0;
        }
    }
    if(sum==0) printf("%d\n",res);
    else printf("-1\n");
    return 0;
}