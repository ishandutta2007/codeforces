#include"bits/stdc++.h"
using namespace std;
int a[200005];
int cl[200005];
set<int>st;
void add(int i)
{
    if(cl[a[i]]==i)return;
    st.insert(cl[a[i]]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        cl[a[i]]=i;
    }
    int ans=1;
    int l=0,r=1;
    while(r!=n)
    {//cout<<"<<"<<l<<" "<<r<<" "<<ans<<endl;
        for(int i=l+1;i<=r;i++)
        {
            add(i);
        }
        if(st.size()==0)
        {
            l=r;
            r++;
            ans++;
            continue;
        }
        l=r;
        auto it=st.end();
        it--;
        r=max(*it,r);
        if(l==r)r++;
        ans++;
    }
    cout<<n-ans<<endl;
    return 0;
}