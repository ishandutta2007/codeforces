#include <iostream>
#include <vector>

#define M 555
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

long n,m,d[M][M],a[M],b[M],ans=0, r[M],t;
vector<long> p[M];
pair<long,long> s[M][M], link,e=mp(-1,-1);

int main()
{
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    cin>>m;
    for (long i=0; i<m; ++i)
    cin>>b[i];
    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j){
        if (a[i]==b[j])
        p[i].pb(j);
        d[i][j]=1;
        s[i][j]=mp(i,j);
    }

    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    if (a[i]==b[j])
    for (long k=i; k>=0; --k)
    for (long t=0; t<p[k].size() && p[k][t]<=j; ++t)
    if (a[k]<a[i])
    if (d[i][j]<d[k][p[k][t]]+1){
        d[i][j]=d[k][p[k][t]]+1;
        s[i][j]=mp(k,p[k][t]);
    }


    for (long i=0; i<n; ++i)
    for (long j=0; j<m; ++j)
    if (a[i]==b[j])
    if (ans<d[i][j]){
        ans=d[i][j];
        link=mp(i,j);
    }

    cout<<ans<<"\n";
    t=ans;

    while (s[link.f][link.s]!=link){
        r[ans--]=a[link.f];
        link=s[link.f][link.s];
    }
    r[ans--]=a[link.f];
    for (long i=1; i<=t; ++i)
    cout<<r[i]<<" ";


    return 0;
}