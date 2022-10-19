#include <iostream>
#include <vector>
#include <algorithm>

#define M 100100
#define f first
#define s second
#define mp make_pair

using namespace std;

long n,m,b[M],ans[M],t;
vector<long> g[M],u;
pair<pair<long,long>,long> q[M];

void read(void){
    cin>>n>>m;
    for (long i=1,a; i<=n; ++i){
        cin>>a;
        if (a<=n)
        g[a].push_back(i);
    }

    for (long i=1; i<=n ;++i)
    if (g[i].size()>=i)
    u.push_back(i);

    t=u.size();

    for (long i=0,l,r; i<m; ++i){
        cin>>l>>r;
        q[i]=mp(mp(l,r),i);
    }

    sort(q,q+m);
}

void work(void){
    long le=0,l,r,ind,x;
    for (long i=0; i<m; ++i){
        l=q[i].f.f;
        r=q[i].f.s;
        ind=q[i].s;
        ans[ind]=0;
        for (long j=0; j<t; ++j){
            x=u[j];
            while(b[x]<g[x].size() && g[x][b[x]]<l)
            b[x]++;
            if (b[x]+x-1<g[x].size() && g[x][b[x]+x-1]<=r){

                if (b[x]+x<g[x].size())
                if (g[x][b[x]+x]>r)
                ++ans[ind];

                if (b[x]+x>=g[x].size())
                ++ans[ind];
            }

        }
    }

}

int main()
{
    read();
    work();
    for (long i=0; i<m; ++i)
    cout<<ans[i]<<"\n";
    return 0;
}