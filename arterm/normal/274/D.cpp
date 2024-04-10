#include <iostream>
#include <algorithm>
#include <vector>

#define M 200100
#define f first
#define s second
#define mp make_pair
#define long long long

using namespace std;

vector<long> g[M],b[M],t[M],ans;
long n,m,bo=0;
long u[M];
bool good=1;
long uv[M];
pair<long,long> p[M];

void read(void){
    cin>>n>>m;
    for (long i=0; i<n; ++i){

        for (long j=1,x; j<=m; ++j){
            cin>>x;
            p[j-1]=mp(x,j);
        }

        sort(p,p+m);

        bool flag=0;

        for (long h=0,j; h<m; ){
            j=h;

            while (j<m && p[h].f==p[j].f)
            ++j;

            if (p[h].f==-1){
                h=j;
                continue;
            }


            for (long k=h; k<j; ++k){
                long x=p[k].s;
                b[bo].push_back(x);
                t[x].push_back(bo);
                if (flag)
                g[x].push_back(bo-1);
            }
            bo++;
            flag=1;

            h=j;
        }
    }
}

void dfs(long v){
    uv[v]=1;

    /*for (long i=0; i<t[v].size(); ++i){
        long tb=t[v][i];
        u[tb]=1;
    }*/

    for (long i=0; i<g[v].size(); ++i){
        long tb=g[v][i];

        if (u[tb]==0)
        for (long j=0; j<b[tb].size(); ++j){
            long to=b[tb][j];

            if (uv[to]==1)
            good=0;

            if (uv[to]==0)
            dfs(to);
        }

        u[tb]=1;
    }


    uv[v]=2;

    ans.push_back(v);


}

int main()
{
    read();
    for (long i=1; i<=m; ++i)
    if (uv[i]==0)
    dfs(i);

    if (!good)
    cout<<"-1\n";
    else
    for (long i=0; i<m; ++i,cout<<" ")
    cout<<ans[i];

    return 0;
}