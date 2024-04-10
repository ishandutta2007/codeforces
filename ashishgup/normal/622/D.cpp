#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N];

int32_t main()
{
    IOS;
    cin>>n;
    if(n==0)
    {
        cout<<"1 1";
        return 0;
    }
    int l=1, r=n;
    for(int cur=1;cur<=n;cur+=2)
    {
        a[l++]=cur;
        a[r--]=cur;
    }
    l=n+1;
    r=2*n - 1;
    for(int cur=2;cur<=n;cur+=2)
    {
        a[l++]=cur;
        a[r--]=cur;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(a[i]==0)
            a[i]=n;
        cout<<a[i]<<" ";
    }
    return 0;
}