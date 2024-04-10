#include"bits/stdc++.h"
using namespace std;
int p[200005],m[200005],pos[200005];
bool cmp(int x,int y)
{
    return p[x]<p[y];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",p+i,m+i);
            pos[i]=i;
        }
        sort(pos,pos+n,cmp);
        multiset<int>st;
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            st.insert(m[pos[i]]);
            while(n-st.size()<p[pos[i]])
            {
                ans+=*st.begin();
                st.erase(st.begin());
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}