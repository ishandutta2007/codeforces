#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1000005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int k=0;
        while(m--)
        {
            int b;
            scanf("%d",&b);
            k=__gcd(k,b);
        }
        if(k>n)return 1;
        ll ans=0,ans2=0;
        set<int>st;
        for(int i=0;i<k;i++)
        {
            st.clear();
            int now=0;
            for(int j=i;j<n;j+=k)
            {
                st.insert(abs(a[j]));
                if(a[j]<=0)now++;
            }
            if(now%2)
            {
                ans-=*st.begin()*2;
            }
            else ans2-=*st.begin()*2;
        }
        for(int i=0;i<n;i++)
        {
            ans+=abs(a[i]);
            ans2+=abs(a[i]);
        }
        printf("%lld\n",max(ans,ans2));
    }
    return 0;
}