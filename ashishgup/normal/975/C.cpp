#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, q, ans;
int a[N];

int32_t main()
{
    IOS;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int cur=0;
    for(int i=1;i<=q;i++)
    {
        int k;
        cin>>k;
        cur+=k;
        if(cur>=a[n])
            ans=n, cur=0;
        else
            ans=a+n+1 - upper_bound(a+1, a+n+1, cur);
        cout<<ans<<endl;
    }
    return 0;
}