#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, q;
int a[N], pref[N], ans[N];

int work(int k)
{
    int ans=0, i=2, cur=k, lift=1;
    while(i<=n)
    {
        int sum=pref[min(n, i+cur-1)] - pref[i-1];
        ans+=sum*lift;
        i=i+cur;
        cur*=k;
        lift++;
    }
    return ans;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1] + a[i];
    for(int i=1;i<=1e5;i++)
        ans[i]=work(i);
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        cout<<ans[k]<<" ";
    }
    return 0;
}