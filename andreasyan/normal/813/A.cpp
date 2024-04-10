#include <bits/stdc++.h>
using namespace std;
const int N=1002;

int n,m;
int a[N],l[N],r[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("lights.in","r",stdin);
    //freopen("lights.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cin>>m;
    int ans=-1;
    for(int i=0;i<m;++i)
    {
        cin>>l[i]>>r[i];
        if(l[i]<=sum && sum<=r[i])
            ans=sum;
        if(l[i]>=sum && ans==-1)
            ans=l[i];
    }
    cout<<ans<<endl;
    return 0;
}