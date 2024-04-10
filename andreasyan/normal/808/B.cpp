#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int n,k;
int a[N];
long long p[N];

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    long double ans=0;
    for(int r=k;r<=n;++r)
    {
        int l=r-k+1;
        ans+=((p[r]-p[l-1]+0.0)/(n-k+1));
    }
    cout<<ans<<endl;
    return 0;
}