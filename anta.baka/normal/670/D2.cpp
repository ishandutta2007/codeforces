#include <bits/stdc++.h>
using namespace std;

inline long long check(int n, int a[], int b[], long long m, int k)
{
    long long sum=0;
    for(int i=0; i<n && sum<=k; i++)
        sum+=max(0ll,m*a[i]-b[i]);
    return (sum<=k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    int a[n], b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    long long l=0, r=(long long)2e9;
    while(l<r)
    {
        long long m=(l+r)/2;
        if(l==m) m++;
        if(check(n,a,b,m,k)) l=m;
        else r=m-1;
    }

    cout<<l;
    return 0;
}