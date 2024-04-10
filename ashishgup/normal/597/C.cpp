#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N], ans[11][N], bit[11][N];

void update(int idx, int i, int val)
{
    while(i<=n)
    {
        bit[idx][i]+=val;
        i+=(i&(-i));
    }
}

int pref(int idx, int i)
{
    int ans=0;
    while(i>=1)
    {
        ans+=bit[idx][i];
        i-=(i&(-i));
    }
    return ans;
}


int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        update(1, a[i], 1);
        for(int curk=2;curk<=k+1;curk++)
            update(curk, a[i], pref(curk-1, a[i]-1));
    }
    int ans=pref(k+1, n);
    cout<<ans;
    return 0;
}