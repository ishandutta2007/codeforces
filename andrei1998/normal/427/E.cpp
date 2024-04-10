#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 1000005

long long int v[NMAX];
long long int st_sum[NMAX];
long long int dr_sum[NMAX];
long long int st_c[NMAX];
long long int dr_c[NMAX];

#define inf 40000000000000000ll

int main()
{
    ios_base::sync_with_stdio(false);

    int n,i,m;
    cin>>n>>m;

    for(i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);

    int x=1%m;
    for(i=1;i<=n;i++)
    {
        st_sum[i]=st_sum[i-1]+st_c[i-1]*(v[i]-v[i-1]);

        st_c[i]=st_c[i-1];
        if(i%m==x)
            st_c[i]++;
    }

    for(i=n;i>=1;i--)
    {
        dr_sum[i]=dr_sum[i+1]+dr_c[i+1]*(v[i+1]-v[i]);

        dr_c[i]=dr_c[i+1];
        if((n-i+1)%m==x)
            dr_c[i]++;
    }

    long long minim=inf;
    for(i=1;i<=n;i++)
        if((st_sum[i]+dr_sum[i])<minim)
            minim=(st_sum[i]+dr_sum[i]);
    cout<<(2*minim)<<'\n';

    return 0;
}