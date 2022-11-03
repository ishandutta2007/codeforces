#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],ans,m,b[1000000],tep;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    tep=1;
    for (int i=1;i<=n;i++)
    {
        while (abs(b[tep+1]-a[i])<=abs(b[tep]-a[i]) && tep+1<=m) tep++;
        ans=max(ans,abs(b[tep]-a[i]));
    }
    cout<<ans;
}