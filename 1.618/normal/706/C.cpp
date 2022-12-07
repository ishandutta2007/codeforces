#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <cassert>
#include <string>
#define maxn 100005
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const ll infll = 0x3f3f3f3f3f3f3f3fll;

int n,c[maxn];
string s[maxn],t[maxn];
struct edge{
  int to,cst;
};
vector <edge> adj[maxn << 1];
ll dis[maxn << 1];
void dijkstra(int s){
  memset(dis,0x3f,sizeof(dis));
  dis[s] = 0;
  priority_queue <P,vector<P>,greater<P> > que;
  que.push(mp(0,s));
  while(!que.empty()){
    P p = que.top(); que.pop();
    if(p.first != dis[p.second]) continue;
    for(int i = 0;i < (int)adj[p.second].size();i++){
      edge e = adj[p.second][i];
      if(p.first + e.cst < dis[e.to]){
        dis[e.to] = p.first + e.cst;
        que.push(mp(dis[e.to],e.to));
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 1;i <= n;i++) cin >> c[i];
  for(int i = 1;i <= n;i++){
    cin >> s[i];
    t[i] = s[i];
    reverse(t[i].begin(),t[i].end());
  }
  adj[0].push_back((edge){1,0});
  adj[0].push_back((edge){n + 1,c[1]});
  for(int i = 1;i < n;i++){
    if(s[i] <= s[i + 1]) adj[i].push_back((edge){i + 1,0});
    if(s[i] <= t[i + 1]) adj[i].push_back((edge){n + i + 1,c[i + 1]});
    if(t[i] <= s[i + 1]) adj[n + i].push_back((edge){i + 1,0});
    if(t[i] <= t[i + 1]) adj[n + i].push_back((edge){n + i + 1,c[i + 1]});
  }
  dijkstra(0);
  ll ans = min(dis[n],dis[n << 1]);
  if(ans == infll) cout << "-1" << endl;
  else cout << ans << endl;
  return 0;
}