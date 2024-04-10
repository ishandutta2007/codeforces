#include <iostream>
#include <vector>

using namespace std;

int const nmax = 200000;

struct Edge{
  int pos;
  int to;
};

vector<Edge> g[5 + nmax];

int v[5 + nmax];
int sol[5 + nmax];
int seen[5 + nmax];

int dfs(int node , int pos){
  seen[node] = 1;
  int sum = 0;
  for(int h = 0 ;h < g[node].size() ;h++){
    Edge e = g[node][h];
    if(seen[e.to] == 0){
      //cout << node << " " << e.to << '\n';
      if(e.pos < 0)
        sum += dfs(e.to , e.pos);
      else
        sum += -dfs(e.to , e.pos);

    }
  }
  if(pos < 0)
    sol[-pos] = -(v[node] - sum);
  else
    sol[pos] = (v[node] - sum);
  if(0 < pos){
    //cout << ":"<<node << " " <<sum << " " <<  sol[pos] << ":" << '\n';
    return sol[pos];
  } else {
    //cout << ":"<<node << " " <<sum << " " <<  sol[-pos] << ":" << '\n';
    return sol[-pos];
  }
}
int main(){
  int n ;
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n ;i++){
    cin >> v[i];
    sum += v[i];
  }
  int m;
  cin >> m;
  for(int i = 1 ; i <= m ;i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back({i , y});
    g[y].push_back({-i , x});
  }

  if(sum != 0){
    cout << "Impossible\n";
    return 0;
  }
  cout << "Possible\n";
  dfs(1 , 0);
  for(int i = 1 ; i <= m ;i++)
    cout << sol[i] << '\n';
  return 0;
}