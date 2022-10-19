#include <iostream>
#include <vector>

#define M 100100

using namespace std;

long n,m,t[M],ans=0,k;
vector<long> g[M],f[M];
bool u[M],flag;

long abs(long x){
    if (x>0)
    return x;
    return -x;
}

long gcd(long x, long y){
    while (x>0){
        y%=x;
        swap(x,y);
    }
    return x+y;
}

long nex(long x){
    x++;
    x%=k;
    if (x<0)
    x+=k;
    return x;
}

long pre(long x){
    x--;
    x%=k;
    if (x<0)
    x+=k;
    return x;
}

void clr(void){
    for (long i=1; i<=n; ++i)
    u[i]=0;
}

void read(void){
    cin>>n>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        g[a].push_back(b);
        f[b].push_back(a);
    }
}

void dfs(long v,long tim){
    u[v]=1;
    t[v]=tim;
    for (long i=0,to; i<g[v].size(); ++i){
        to=g[v][i];
        if (!u[to])
        dfs(to,tim+1);
        else
        ans=gcd(ans,abs(tim+1-t[to]));
    }
    for (long i=0,to; i<f[v].size(); ++i){
        to=f[v][i];
        if (!u[to])
        dfs(to,tim-1);
        else
        ans=gcd(ans,abs(tim-1-t[to]));
    }
}

void tryit(long v, long c){
    u[v]=1;
    t[v]=c;
    for (long i=0,to,nc=nex(c); i<g[v].size(); ++i){
        to=g[v][i];
        if (!u[to])
        tryit(to,nc);
        else
        if (nc!=t[to])
        flag=0;
    }
    for (long i=0,to,pc=pre(c); i<f[v].size(); ++i){
        to=f[v][i];
        if (!u[to])
        tryit(to,pc);
        else
        if (pc!=t[to])
        flag=0;
    }

}

int main()
{
    read();

    for(long i=1; i<=n; ++i)
    if (!u[i])
    dfs(i,0);


    if (ans==0)
    ans=n;
    else
    for (long j=ans; j>0; --j)
    if (ans%j==0){
        clr();
        flag=1;
        k=j;
        for(long i=1; i<=n; ++i)
        if (!u[i])
        tryit(i,0);

        if (flag){
            ans=j;
            break;
        }
    }


    cout<<ans;
    return 0;
}