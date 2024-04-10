#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[200005];
char t[200005];
int pos[1005];
int nums[1005];
int vis[200005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cin>>s>>t;
        ll ans=1e18;
        ll now=0;
        for(int i='a';i<='z';i++)pos[i]=nums[i]=0;
        for(int i=0;i<=n;i++)vis[i]=0;
        int num=0;
        for(int i=0;i+num<n;)
        {
            for(int c='a';c<='z';c++)
            {
                for(;pos[c]<n;pos[c]++)
                {
                    if(vis[pos[c]])nums[c]--;
                    else if(s[pos[c]]==c)break;
                }
            }
            if(vis[i]==1)
            {
                i++;
                num--;
                continue;
            }
            if(s[i]<t[i+num])
            {
                ans=min(now,ans);
                break;
            }
            int k=n;
            for(int c='a';c<t[i+num];c++)k=min(k,pos[c]+nums[c]);
            if(k!=n)ans=min(now+k-i-num,ans);
            if(pos[t[i+num]]<k)k=pos[t[i+num]]+nums[t[i+num]];
            else break;
            now+=k-i-num;
            vis[pos[t[i+num]]]=1;
            for(int c='a';c<='z';c++)if(pos[c]<=pos[t[i+num]])nums[c]++;
            num++;
        }
        if(ans==1e18)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}