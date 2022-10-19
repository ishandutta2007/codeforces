#include <bits/stdc++.h>
using namespace std;
const int N=1005;

int n,m;
int a[N];

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=9999999;
    for(int i=1;i<=n;++i)
        ans=min(ans,a[i]);
    cout<<ans<<endl;
    return 0;
}