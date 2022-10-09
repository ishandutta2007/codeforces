#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 100000;
vector<int> g[1 + nmax];
ld const precision = 30;
int fort[1 + nmax], active[1 + nmax];
ld frec[1 + nmax];

struct Number{
  ld rat;
  int id;
  bool operator < (Number const &a) const{
    return a.rat < rat;
  }
};

bool solve(int n, ld rat){
  for(int i = 1;i <= n; i++)
    frec[i] = 0;

  for(int i = 1; i <= n; i++)
    if(fort[i] == 0)
      active[i] = 1;
    else
      active[i] = 0;

  for(int i = 1; i <= n; i++)
    if(active[i] == 1)
      for(int h = 0; h < g[i].size(); h++)
        frec[g[i][h]] += 1;

  priority_queue<Number> pq;
  for(int i = 1;i <= n; i++)
    if(active[i] == 1)
      pq.push({frec[i] / g[i].size(), i});


  while(0 < pq.size()){
    Number pqtop = pq.top();
    pq.pop();
    if(active[pqtop.id] == 0)
      continue;
    if(pqtop.rat < rat) {
      int node = pqtop.id;
      active[node] = 0;
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h];
        frec[to] -= 1;
        if(active[to] == 1)
          pq.push({frec[to] / g[to].size(), to});
      }
    }
  }

  for(int i = 1;i <= n; i++)
    if(active[i] == 1)
      return 1;
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1;i <= k; i++){
    int val;
    cin >> val;
    fort[val] = 1;
  }

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  ld from = 0, to = 1;
  for(int i = 1;i <= precision; i++){
    ld mid = (to + from) / 2;
    if(solve(n, mid) == 1)
      from = mid;
    else
      to = mid;
  }
  solve(n, from);

  int sz = 0;
  for(int i = 1;i <= n; i++)
    sz += active[i];
  cout << sz << '\n';
  for(int i = 1;i <= n; i++)
    if(active[i] == 1)
      cout << i << " ";
  return 0;
}