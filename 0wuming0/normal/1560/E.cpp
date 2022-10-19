#include"bits/stdc++.h"
using namespace std;
char s[500005];
char ans2[35];
int nn=29;
char ans[500005];
char ss[500005];
int sn;
int vis[505];
int num[505];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i='a';i<='z';i++)vis[i]=num[i]=0;
        nn=29;
        scanf("%s",s);
        int n=strlen(s);
        int sz=0;
        for(int i=n-1;i>=0;i--)
        {
            if(vis[s[i]]==0)
            {
                vis[s[i]]=1;
                nn--;
                ans2[nn]=s[i];
                sz++;
            }
            num[s[i]]++;
        }
        int now=1;
        int sum=0;
        for(int i=nn;i<29;i++)
        {
            if(num[ans2[i]]%now)
            {
                printf("-1\n");
                goto ne;
            }
            num[ans2[i]]/=now;
            sum+=num[ans2[i]];
            now++;
        }
        for(int i=0;i<sum;i++)ans[i]=s[i];
        ans[sum]=0;
        sn=0;
        for(int i=nn;ans2[i];i++)
        {
            for(int j=0;j<sum;j++)if(vis[ans[j]])
            {
                ss[sn++]=ans[j];
                if(sn==500003)
                {
                    printf("-1\n");
                    goto ne;
                }
            }
            vis[ans2[i]]=0;
        }
        ss[sn]=0;
        //cout<<"<<"<<ans<<" "<<ans2+nn<<"   "<<ss<<endl;
        if(strcmp(ss,s))
        {
            printf("-1\n");
            //printf("%s %s\n",ans,ans2+nn);
        }
        else printf("%s %s\n",ans,ans2+nn);
        ne:;
    }
    return 0;
}