#include <iostream>
#include <vector>
#include <set>

#define M 300

using namespace std;

vector<bool> u(M,0);
vector<long> g[M];
long n,c[M];

void read(void){
    cin>>n;

    for (long i=1; i<=n; ++i)
    cin>>c[i];

    for (long i=1,k,a; i<=n; ++i){
        cin>>k;
        for (long j=0; j<k; ++j){
            cin>>a;
            g[i].push_back(a);
        }
    }
}

long next(long a){
    a++;
    if (a>3)
    a-=3;
    return a;
}

bool check(long a){
    for (long i=0; i<g[a].size(); ++i)
    if (!u[g[a][i]])
    return 0;
    return 1;
}

long doit(long f){
    long d=0,t=0;
    for (long i=1; i<=n; ++i)
    u[i]=0;
    while (d!=n){
        for (long j=1; j<=n; ++j)
        for (long i=1; i<=n; ++i)
        if (!u[i] && c[i]==f && check(i)){
            u[i]=1;
            t++;
            d++;
        }
        f=next(f);
        if (d!=n)
        t++;
    }

    return t;
}

int main()
{
    read();
    long m=10000;
    for (long i=1; i<=3; ++i)
    m=min(m,doit(i));
    cout<<m;
    return 0;
}