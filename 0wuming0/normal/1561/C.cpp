#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        multimap<int,int>mp;
        int ans=0;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int k;
            scanf("%d",&k);
            int m=0;
            for(int i=0;i<k;i++)
            {
                int a;
                scanf("%d",&a);
                m=max(a-i,m);
            }
            mp.insert(make_pair(m+1,k));
        }
        int now=0;
        while(mp.size())
        {
            if(now<mp.begin()->first)
            {
                ans+=mp.begin()->first-now;
                now=mp.begin()->first;
            }
            now+=mp.begin()->second;
            mp.erase(mp.begin());
        }
        printf("%d\n",ans);
    }
    return 0;
}