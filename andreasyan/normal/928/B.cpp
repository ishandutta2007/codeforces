#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005

int n,k;
int a[N],ans[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int l=max(i-k,1),r=min(i+k,n);
        if(a[i]==0)
        {
            ans[i]=(r-l+1);
            continue;
        }
        int ll=max(a[i]-k,1),rr=min(a[i]+k,n);
        if(l>rr)
        {
            ans[i]=ans[a[i]]+(r-l+1);
        }
        else
        {
            ans[i]=ans[a[i]]+(r-rr);
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}