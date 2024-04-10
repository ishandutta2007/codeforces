#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, add=0;
int a[N], b[N], ans[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-(n-i);
    }
    sort(b+1, b+n+1);
    int curmin=b[n];
    for(int i=n;i>=1;i--)
    {
        ans[i]=b[i]+add;
        if(ans[i]>curmin)
        {
            cout<<":(";
            return 0;
        }
        add++;
        curmin=min(curmin, ans[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}