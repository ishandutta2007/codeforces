#include"bits/stdc++.h"
using namespace std;
map<long long,int>mp;
long long ans;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        long long now=0;
        long long save=0;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            now+=a;
            if(now>save)
            {
                save=now;
                mp[save]=i;
            }
        }
        for(int i=0;i<m;i++)
        {
            int a;
            scanf("%d",&a);
            map<long long,int>::iterator it=mp.lower_bound(a);
            if(it!=mp.end())ans=it->second;
            else if(now<=0)ans=-1;
            else
            {
                //a-k*now<=save
                long long k=(a-save)/now;
                a-=k*now;
                if(a>save)a-=now,k++;
                ans=n*k+(mp.lower_bound(a))->second;
            }
            printf("%lld%c",ans," \n"[i==m-1]);
        }
    }
    return 0;
}