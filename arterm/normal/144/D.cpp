#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define long long long

const long  M=100100,INF=200000000000000LL;

struct edge{
       long a,b,w;
       };

vector<edge> e;
vector<long> d(M,INF),p(M),path;
vector<pair<long,long> > g[M];
set<pair<long,long> > s;

int main()
{
    long n,m,a,b,w,i,to,st,l,ans=0,x,y;
    double len;
    cin>>n>>m>>st;
    for (i=0; i<m; ++i){
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
        edge e1={a,b,w};
        e.push_back(e1);
        }
    d[st]=0;
    p[st]=st;
    s.insert(make_pair(d[st],st));
    while (!s.empty()){
          b=s.begin()->second;
          s.erase(s.begin());
          for (i=0; i<g[b].size(); ++i){
              to=g[b][i].first;
              w=g[b][i].second;
              if (d[to]>d[b]+w){
                                s.erase(make_pair(d[to],to));
                                d[to]=d[b]+w;
                                s.insert(make_pair(d[to],to));
                                p[to]=b;
                                }
              }
          }
    cin>>l;
    for (i=1; i<=n; ++i)
    if (d[i]==l)
    ++ans;
    for (i=0; i<m; ++i)
    if (d[e[i].a]<l || d[e[i].b]<l){
                    x=e[i].a;
                    y=e[i].b;
                    if (d[x]>d[y])
                    swap(x,y);
                    len=(double) (d[x]+d[y]+e[i].w)/2;
                    //cout<<len<<endl;
                    if (l-d[x]<e[i].w)
                    if (len>=l)
                    ++ans;
                    if (l-d[y]<e[i].w && l-d[y]>0)
                    if (len>l)
                    ++ans;
                    }
    cout<<ans;
    //system("PAUSE");
    return 0;
}