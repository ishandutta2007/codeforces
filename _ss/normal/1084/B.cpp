#include <iostream>

using namespace std;
long long a[1001],s,n;
int main()
{
    cin>>n>>s;
    for (long long i=1;i<=n;i++) cin>>a[i];
    long long x=0,m=int(2e9);
    for (long long i=1;i<=n;i++)
    {
        x=x+a[i];
        if (a[i]<m) m=a[i];
    }
    if (x<s) cout<<-1;
    else
    {
    for (long long i=1;i<=n;i++) s=s-(a[i]-m);
    if (s<=0) cout<<m; else cout <<m-(s+n-1)/n;
    }
    return 0;
}