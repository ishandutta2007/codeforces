#include"bits/stdc++.h"
using namespace std;
int a[200005];
int p[200005],s[200005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        cin>>m;
        map<int,int>mp;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            auto it=mp.find(a);
            if(it==mp.end())mp[a]=b;
            else if(it->second<b)it->second=b;
        }
        nn=0;
        for(auto pr:mp)
        {
            if(nn!=0&&pr.second>s[nn-1])
            {
                while(nn!=0&&pr.second>s[nn-1])
                nn--;
            }
            p[nn]=pr.first;
            s[nn]=pr.second;
            nn++;
        }
        int now=0;
        int ans=0;
        for(int i=0;i<n;i++)if(a[i]>p[nn-1])
        {
            cout<<-1<<endl;
            goto ne;
        }
        a[n]=1e9+3;
        while(1)
        {
            if(now>=n)break;
            int nows=0;
            int maxp=0;
            ans++;
            int x1=0,x2=nn,x;
            while(x1+1!=x2)
            {
                x=(x1+x2)/2;
                if(s[x]<=nows)
                {
                    x2=x;
                }
                else if(p[x]>=a[now]&&p[x]>=maxp)
                {
                    while(p[x]>=a[now]&&p[x]>=maxp&&s[x]>nows)
                    {
                        maxp=max(maxp,a[now]);
                        now++;
                        nows++;
                    }
                }
                else x1=x;
            }
            x=x1;
            while(p[x]>=a[now]&&p[x]>=maxp&&s[x]>nows)
            {
                maxp=max(maxp,a[now]);
                now++;
                nows++;
            }
            //cout<<"<<<<"<<ans<<" "<<now<<" "<<x<<endl;
        }
        cout<<ans<<endl;
        ne:;
    }
    return 0;
}
/*
2
2
1 2
1
3 3
*/