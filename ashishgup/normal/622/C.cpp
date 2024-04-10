#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int a[N], nxt[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    nxt[n]=n+1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]!=a[i+1])
            nxt[i]=i+1;
        else
            nxt[i]=nxt[i+1];
    }
    while(m--)
    {
        int l, r, x;
        cin>>l>>r>>x;
        if(a[l]==x)
        {
            if(nxt[l]<=r)
                cout<<nxt[l]<<endl;
            else
                cout<<"-1"<<endl;
        }
        else
            cout<<l<<endl;
    }
    return 0;
}