#include <cstdlib>
#include <iostream>
#include <vector>

#define M 3030

using namespace std;

long n,p[M],go=-1;
vector<bool> r(M,0),c(M,0);
vector<long> g[M], ans(M,-1);

void read(void){
     long a,b;
     cin>>n;
     for (long i=0; i<n; ++i){
         cin>>a>>b;
         g[a].push_back(b);
         g[b].push_back(a);
         }
     }
     
void fc(long s, long f){
     for (long i=s; i!=f; i=p[i])
     r[i]=1;
     r[f]=1;
     }
     
void color(long x){
     c[x]=1;
     for(long i=0; i<g[x].size(); ++i)
     if (!c[g[x][i]]){
                      p[g[x][i]]=x;
                      color(g[x][i]);
                      }
     else
     if (g[x][i]!=p[x] && go==-1){
                       go=g[x][i];
                       fc(x,go);
                       }
     }
     
void dfs(long x,long t){
     ans[x]=t;
     for (long i=0; i<g[x].size(); ++i)
     if (ans[g[x][i]]==-1 && !r[g[x][i]])
     dfs(g[x][i],t+1);
     }
     
long find(void){
     for(long i=1; i<=n; ++i)
     if (r[i])
     dfs(i,0);
     for (long i=1; i<=n; ++i)
     cout<<ans[i]<<" ";
     }

int main()
{
    read();
    color(1);
    find();
    //system("PAUSE");
    return 0;
}