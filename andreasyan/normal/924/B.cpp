#include <bits/stdc++.h>
using namespace std;
const int N=100003,INF=1000000007;

int n,u;
long double a[N];

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);
    cin>>n>>u;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    long double ans=-1;
    for(int i=0;i<n;++i)
    {
        int k=upper_bound(a+i+2,a+n,a[i]+u)-a-1;
        if(k>=(i+2) && k<n && a[k]-a[i]<=u)
        {
            ans=max(ans,(a[k]-a[i+1])/(a[k]-a[i]));
        }
    }
    if(ans<0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}