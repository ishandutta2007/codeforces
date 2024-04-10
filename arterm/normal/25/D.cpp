#include <iostream>

#define M 1007
#define mp make_pair
#define f first
#define s second

using namespace std;

long p[M],n,t=0;
pair<long, long> c[M];

void init(void){
    for (long i=1; i<M; ++i)
    p[i]=i;
}

long get(long x){
    if (p[x]==x)
    return x;
    else
    return p[x]=get(p[x]);
}

void uni(long a, long b){
    a=get(a);
    b=get(b);
    p[a]=b;
}

void read(void){
    cin>>n;
    for (long i=1,a,b; i<n; ++i){
        cin>>a>>b;
        if (get(a)==get(b))
        c[t++]=mp(a,b);
        uni(a,b);
    }
}

void doit(void){
    cout<<t<<"\n";
    for (long i=0; i<t; ++i){
        cout<<c[i].f<<" "<<c[i].s<<" ";
        for (long j=1; j<=n; ++j)
        if (get(c[i].f)!=get(j)){
            cout<<c[i].f<<" "<<j<<"\n";
            uni(c[i].f,j);
            break;
        }
    }
}

int main()
{
    init();
    read();
    doit();
    return 0;
}