#include <iostream>

#define M 2222

using namespace std;

long n,m,s[M],p[M],ans=0;
bool f[M];

void ini(void){
    for (long i=1; i<=n; ++i){
        s[i]=1;
        p[i]=i;
    }
}

long get(long x){
    if (p[x]==x)
    return x;
    return p[x]=get(p[x]);
}

void uni(long x, long y){
    x=get(x);
    y=get(y);
    if (x!=y)
    s[y]+=s[x];
    p[x]=y;

}


int main()
{
    cin>>n>>m;
    ini();
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        uni(a,b);
    }
    cin>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        if (get(a)==get(b))
        f[get(a)]=1;
    }

    for (long i=1; i<=n; ++i)
    if (!f[get(i)])
    ans=max(ans,s[get(i)]);

    cout<<ans;

    return 0;
}