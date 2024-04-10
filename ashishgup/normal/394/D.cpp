#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, storediff, firstelem;
int a[N], b[N][2];

int check(int k)
{
    for(int diff=0;diff<=b[2][1]-b[1][0] && diff<=(b[n][1]-b[1][0])/(n-1) + 1;diff++)
    {
        for(int i=1;i<=n;i++)
        {
            b[i][0]=a[i]-k;
            b[i][1]=a[i]+k;
        }
        int minelem=b[1][0], maxelem=b[1][1];
        for(int i=2;i<=n;i++)
        {
            minelem=max(minelem, b[i][0]-(i-1)*diff);
            maxelem=min(maxelem, b[i][1]-(i-1)*diff);
        }
        firstelem=minelem;
        storediff=diff;
        if(minelem<=maxelem)
            return true;
    }
    return false;;
}

int binsearch(int lo, int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(check(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    check(lo);
    return lo;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    int range=binsearch(0, 1e5);
    cout<<range<<endl;
    cout<<firstelem<<" "<<storediff;
    return 0;
}