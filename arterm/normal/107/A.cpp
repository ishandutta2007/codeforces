#include <iostream>

#define M 1010
#define INF 100000000

using namespace std;

long p[M],m[M],n,t[M],d[M],r,ans=0;
bool in[M],out[M];


void ini(void){
    for (long i=0; i<M; ++i)
    p[i]=i,m[i]=INF,t[i]=i,d[i]=i;
}

long get(long x){
    return p[x]==x ? x:p[x]=get(p[x]);
}

void uni(long x, long y, long di){
    x=get(x);
    y=get(y);
    d[x]=d[y];
    p[y]=x;
    m[x]=min(m[x],m[y]);
    m[x]=min(m[x],di);

}

void read(void){
    cin>>n>>r;
    for (long a,b,di,i=0; i<r; ++i){
        cin>>a>>b>>di;
        in[b]=1;
        out[a]=1;
        uni(a,b,di);
    }
    for (long i=1; i<=n; ++i)
    if (p[i]==i && !in[t[i]] && out[t[i]])
    ++ans;

    cout<<ans<<"\n";

    for (long i=1; i<=n; ++i)
    if (p[i]==i && !in[t[i]] && out[t[i]])
    cout<<t[i]<<" "<<d[i]<<" "<<m[i]<<"\n";

}

int main()
{
    ini();
    read();
    return 0;
}