#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll s[400005],nn;
multiset<ll>st;
void add(ll a)
{
    auto it=st.find(a);
    if(it!=st.end())
    {
        st.erase(it);
    }
    else s[nn++]=a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        st.clear();
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            st.insert(a);
            sum+=a;
        }
        nn=0;
        add(sum);
        while(st.size())
        {
            ll now=s[--nn];
            ll a=now/2;
            ll b=now-a;
            add(a);
            add(b);
            if(nn>n+5)
            {
                cout<<"no"<<endl;
                goto ne;
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}