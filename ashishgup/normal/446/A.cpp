#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N], start[N], finish[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
            finish[i]=finish[i-1]+1;
        else
            finish[i]=1;
        ans=max(ans, finish[i]);
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]<a[i+1])
            start[i]=start[i+1]+1;
        else
            start[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i+1]-a[i-1]>1)
        {
            ans=max(ans, 1 + finish[i-1] + start[i+1]);
        }
        ans=max(ans, 1 + finish[i-1]);
        ans=max(ans, 1 + start[i+1]);
    }
    cout<<ans;
    return 0;
}