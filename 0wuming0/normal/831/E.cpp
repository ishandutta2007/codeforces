#include"bits/stdc++.h"
using namespace std;
int a[100005];
int l[350],r[350];
int pos[100005];
int p[350];
int num[350];
multiset<int>st;
int main()
{
    int n;
    cin>>n;
    int nums=0,nn=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        st.insert(a[i]);
        if(l[nn]==0)
        {
            l[nn]=i;
            p[nn]=1e9;
        }
        r[nn]=i;
        nums++;
        pos[i]=nn;
        num[nn]++;
        p[nn]=min(p[nn],a[i]);
        if(nums%350==0)
        {
            nums=0;
            nn++;
        }
    }
    long long ans=0;
    int now=1;
    while(n--)
    {
        int k=*st.begin();
        st.erase(st.begin());
        int nowp;
        for(nowp=0;;nowp++)if(l[nowp]<=now&&now<=r[nowp])break;
        for(;now<=r[nowp];now++)if(a[now])
        {
            ans++;
            if(a[now]==k)
            {
                a[now]=0;
                num[pos[now]]--;
                goto ed;
            }
        }
        nowp++;
        for(;nowp<350;nowp++)
        {
            if(p[nowp]==k)
            {
                now=l[nowp];
                break;
            }
            else ans+=num[nowp];
        }
        if(nowp==350)
        {
            for(nowp=0;;nowp++)
            {
                if(p[nowp]==k)
                {
                    now=l[nowp];
                    break;
                }
                else ans+=num[nowp];
            }
        }
        for(;now<=r[nowp];now++)if(a[now])
        {
            ans++;
            if(a[now]==k)
            {
                a[now]=0;
                num[pos[now]]--;
                goto ed;
            }
        }
        ed:;
        for(nowp=0;;nowp++)if(l[nowp]<=now&&now<=r[nowp])break;
        p[nowp]=1e9;
        for(int i=l[nowp];i<=r[nowp];i++)
        {
            if(a[i])p[nowp]=min(p[nowp],a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}