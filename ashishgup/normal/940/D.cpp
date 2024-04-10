#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], b[N];

int32_t main()
{
    cin>>n;
    int l=-1e9, r=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        b[i]=ch-'0';
    }
    for(int i=5;i<=n;i++)
    {
        int ct0=0, ct1=0;
        for(int j=i-1;j>=i-4;j--)
        {
            if(b[j]==0)
                ct0++;
            else
                ct1++;
        }
        if(ct0==4 && b[i]==1)
        {
            for(int j=i;j>=i-4;j--)
            {
                l=max(l, a[j] + 1);
            }
        }
        else if(ct1==4 && b[i]==0)
        {
            for(int j=i;j>=i-4;j--)
            {
                r=min(r, a[j] - 1);
            }
        }
    }
    cout<<l<<" "<<r;
    return 0;
}