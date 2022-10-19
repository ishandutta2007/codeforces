#include"bits/stdc++.h"
using namespace std;
struct _
{
    int v;
    int pos;
};
vector<_> a[100005];
int ans[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        _ b;
        int p,q;
        cin>>p>>q;
        b.v=q;
        b.pos=i;
        a[p].push_back(b);
        b.v=q;
        a[q].push_back(b);
    }
    for(int i=1;i<n;i++)
    {
        ans[i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].size()>=3)
        {
            int n1,n2,n3;
            n1=a[i][0].pos;
            n2=a[i][1].pos;
            n3=a[i][2].pos;
            int now=3;
            #define i ii
            for(int i=1;i<n;i++)
            {
                if(i==n1)ans[i]=0;
                else if(i==n2)ans[i]=1;
                else if(i==n3)ans[i]=2;
                else ans[i]=now++;
            }
            break;
        }
    }
    for(int i=1;i<n;i++)cout<<ans[i]<<endl;
    return 0;
}