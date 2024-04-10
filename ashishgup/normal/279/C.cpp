#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], lastinc[N], lastdec[N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    lastinc[n]=n, lastdec[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<=a[i+1])
            lastinc[i]=lastinc[i+1];
        else
            lastinc[i]=i;
        if(a[i]>=a[i+1])
            lastdec[i]=lastdec[i+1];
        else
            lastdec[i]=i;
    }
    while(m--)
    {
        int l, r;
        cin>>l>>r;
        if(lastdec[lastinc[l]]>=r)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}