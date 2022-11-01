#include <bits/stdc++.h>
using namespace std;
long long sum;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    int l=1, r=2000000000;
    while(l<r)
    {
        int m=(1ll*l+r)/2;
        if(l==m) m++;
        sum=0;
        for(int i=0; i<n; i++) sum+=max(0,m-a[i]);
        if(sum<=k)  l=m;
        else        r=m-1;
    }

    sum=0;
    for(int i=0; i<n; i++) { sum+=max(0,l-a[i]); a[i]=max(l,a[i]); }
    for(int i=0; i<n && sum<k; i++) if(a[i]==l) { sum++; a[i]++; }


    l=1, r=2000000000;
    while(l<r)
    {
        int m=(1ll*l+r)/2;
        sum=0;
        for(int i=0; i<n; i++) sum+=max(a[i]-m,0);
        if(sum<=k)  r=m;
        else        l=m+1;
    }

    sum=0;
    for(int i=0; i<n; i++) { sum+=max(a[i]-l,0); a[i]=min(l,a[i]); }
    for(int i=0; i<n && sum<k; i++) if(a[i]==l) { sum++; a[i]--; }

    sort(a,a+n);
    cout<<a[n-1]-a[0];
    return 0;
}