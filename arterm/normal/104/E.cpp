#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>

#define R 1000
#define M 300100
#define mp make_pair
#define f first
#define s second
#define long long long

using namespace std;

long w[M],n,p,ans[M],d[M];
pair<pair<long,long>,long> q[M];

void dir(long b){
     for (long i=n-1; i>=0; --i)
     if (i+b<n)
     d[i]=d[i+b]+w[i];
     else
     d[i]=w[i];
     }

long sim(long a,long b){
     long an=0;
     for (long i=a; i<n; i+=b)
     an+=w[i];
     return an;
     }


int main()
{
    long r,a,b;
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>w[i];
    cin>>p;
    for (long i=0; i<p; ++i){
        cin>>a>>b;
        q[i]=mp(mp(b,a-1),i);
        }
    sort(q,q+p);
    //r=(long)sqrt(n);
    r=R;
    for (long i=0; i<p; ++i)
    if (q[i].f.f<=r){
                     if (i==0 || q[i].f.f!=q[i-1].f.f)
                     dir(q[i].f.f);
                     ans[q[i].s]=d[q[i].f.s];
                     }
    else
    ans[q[i].s]=sim(q[i].f.s,q[i].f.f);
    for (long i=0; i<p; ++i)
    cout<<ans[i]<<endl;
    //system("PAUSE");
    return 0;
}