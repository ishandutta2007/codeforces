#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        char s[n+1];
        scanf("%s",s);
        int cnt=0;
        vector<bool> vis(n,0);
        char res[n+1];
        res[n]='\0';
        for(int i=0;i<n;i++)
        {
            if(a>0&&s[i]=='S')
            {
                a--;
                res[i]='R';
                vis[i]=1;
                cnt++;
            }
            if(b>0&&s[i]=='R')
            {
                b--;
                res[i]='P';
                vis[i]=1;
                cnt++;
            }
            if(c>0&&s[i]=='P')
            {
                c--;
                res[i]='S';
                vis[i]=1;
                cnt++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(a>0)
                {
                    res[i]='R';
                    a--;
                }
                else if(b>0)
                {
                    res[i]='P';
                    b--;
                }
                else if(c>0)
                {
                    res[i]='S';
                    c--;
                }
            }
        }
        if(cnt>=((n+1)/2))
        {
            printf("YES\n");
            printf("%s\n",res);
        }
        else printf("NO\n");
    }
    return 0;
}