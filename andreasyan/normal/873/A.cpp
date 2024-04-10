#include <bits/stdc++.h>
using namespace std;
const int N=1003;

int n,k,x;
int a[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("hall.in","r",stdin);
    //freopen("hall.out","w",stdout);
    cin>>n>>k>>x;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=n-1,j=0;i>=0 && j<k;--i,++j)
    {
        if(a[i]<=x)
            break;
        a[i]=x;
    }
    int ans=0;
    for(int i=0;i<n;++i)
        ans+=a[i];
    cout<<ans<<endl;
    return 0;
}