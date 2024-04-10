#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)

ll n,q,a[N],b[N],nex[N],pre[N];

int main()
{
    ios_base::sync_with_stdio();cin.tie();cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(i)a[i]=abs(b[i]-b[i-1]);
    }
    stack <int> st;
    st.push(1);
    for(int i=2;i<n;i++)
    {
        while(st.size() && a[i]>=a[st.top()])
            nex[st.top()]=i,st.pop();
        st.push(i); 
    }
    while(st.size())
        nex[st.top()]=n,st.pop();
    st.push(n-1);
    for(int i=n-2;i>0;i--)
    {
        while(st.size() && a[i]>a[st.top()])
            pre[st.top()]=i,st.pop();
        st.push(i);     
    }   
    while(st.size())
        pre[st.top()]=0,st.pop();
    while(q--)
    {
        ll l,r,ans=0;
        cin>>l>>r;
        for(int i=l;i<r;i++)
            ans+=a[i]*((min(nex[i],r)-i)*(i-max(pre[i]+1,l)+1));
        cout<<ans<<endl;    
    }       
    return 0;
}