#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        multiset<int>st;
        while(m--)
        {
            int a;
            scanf("%d",&a);
            st.insert(a);
        }
        int now=0,ans=0;
        while(st.size())
        {
            auto it=st.end();
            it--;
            if(now>=*it)
            {
                break;
            }
            now+=n-*it;
            st.erase(it);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}