#include <iostream>
#include <algorithm>

#define M 100100
#define INF 10000000

using namespace std;

long n,a[M],b[M],f[2*M],g[10],h;

void read(){
    cin>>n;
    h=(n+1)/2;
    f[0]=0;
    for (long i=0; i<n; ++i){
        cin>>a[i]>>b[i];
        f[++f[0]]=a[i];
        f[++f[0]]=b[i];
    }
    sort(f+1,f+(f[0]+1));
}

void findpos(void){
    g[0]=0;
    for (long i=1,j,t; i<=f[0]; ){
        j=i;
        t=0;
        while (i<=f[0] && f[j]==f[i]){
            ++i;
            ++t;
        }
        if (t>=h)
        g[++g[0]]=f[j];
    }
}

long findval(long x){
    long u=0,d=0;
    for (long i=0; i<n;++i)
    if (a[i]==x)
    ++u;
    else
    if (b[i]==x)
    ++d;

    if (u+d<h)
    return INF;

    if (u>=h)
    return 0;

    return h-u;
}

int main()
{
    long ans=INF;
    read();
    findpos();
    for (long i=1; i<=g[0]; ++i)
    ans=min(ans,findval(g[i]));
    if (ans==INF)
    cout<<-1;
    else
    cout<<ans;
    return 0;
}