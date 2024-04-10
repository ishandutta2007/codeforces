#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        char s[n+1];
        scanf("%s",s);
        vector<int> t(n);
        t[0]=(s[0]=='0'?1:-1);
        for(int i=1;i<n;i++) t[i]=t[i-1]+(s[i]=='0'?1:-1);
        int d=t[n-1];
        int res=(x==0);
        if(d==0)
        {
            for(int i=0;i<n;i++) if(t[i]==x) res=-1;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                int k=(x-t[i])/d;
                res+=(((x-t[i])%d)==0&&k>=0);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}