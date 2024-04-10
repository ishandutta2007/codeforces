#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define long long long

const long  M=100100,INF=200000000000000LL;

vector<long> d(M,INF),p(M),path;
vector<pair<long,long> > g[M];
set<pair<long,long> > s;

int main()
{
    long n,m,a,b,w,i,to;
    cin>>n>>m;
    for (i=0; i<m; ++i){
        cin>>a>>b>>w;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
        }
    d[1]=0;
    p[1]=1;
    s.insert(make_pair(d[1],1));
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
    if (d[n]==INF){
                   cout<<-1;
                   return 0;
                   }
    to=n;
    while (to!=1){
          path.push_back(to);
          to=p[to];
          }
    path.push_back(1);
    reverse(path.begin(),path.end());
    //cout<<d[n]<<endl;
    for (vector<long>::const_iterator k=path.begin(); k!=path.end(); k++)
    cout<<*k<<" ";
  
    return 0;
}