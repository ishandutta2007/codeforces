#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

struct Edge{
  int to;
  int flow;
  int id;
  int rev;
};
vector<Edge> g[1 + nmax];
ll cap[1 + nmax], sol[1 + nmax], active[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    g[x].push_back({y, cost, i, 0});
    g[y].push_back({x, cost, i, 1});

    cap[x] += cost;
    cap[y] += cost;
  }
  for(int i = 1;i <= n; i++)
    cap[i] /= 2;
  queue<int> q;
  q.push(1);
  active[1] = 1;

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++){
      Edge e = g[node][h];
      if(active[e.to] == 0){
        sol[e.id] = e.rev;
        cap[e.to] -= e.flow;
        if(n != e.to && cap[e.to] == 0) {
          q.push(e.to);
          active[e.to] = 1;
        }
      }
    }
  }
  for(int i = 1;i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}