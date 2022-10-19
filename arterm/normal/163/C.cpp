#include <iostream>
#include <algorithm>

#define M 100100
#define mp make_pair
#define f first
#define s second

using namespace std;

long n;
double v1,v2,d,l,a[M],p[M];
pair<double, bool> s[2*M];

void read(void){
    cin>>n>>l>>v1>>v2;
    d=l*v2/(v1+v2);
    for (long i=0; i<n; ++i)
    cin>>a[i];
}

void doit(void){
    double le=0;
    long t=0;

    for (long i=0; i<n; ++i)
    s[i]=mp(a[i],1);
    for (long i=n; i<2*n; ++i)
    if (a[i-n]+d<=2*l)
    s[i]=mp(a[i-n]+d,0);
    else
    s[i]=mp(a[i-n]+d-2*l,0);
    sort(s,s+(2*n));

    for (long i=0; i<n; ++i)
    if (a[i]>2*l-d)
    ++t;



    for (long i=0; i<2*n; ++i){
        p[t]+=(s[i].f-le);
        le=s[i].f;
        if (s[i].s)
        ++t;
        else
        --t;
    }

    p[t]+=(2*l-le);

    cout.precision(18);

    for (long i=0; i<=n; ++i)
    cout<<fixed<<p[i]/(2*l)<<"\n";

}

int main()
{
    read();
    doit();
    return 0;
}