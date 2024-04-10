#include <iostream>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))


int const nmax = 1000000;
vector<int> g[1 + nmax];
int selfloops = 0;
int seen[1 + nmax];
int self[1 + nmax];

bool isconex(int node, int n){
  queue<int> q;
  q.push(node);
  seen[node] = 1;
  while(0 < q.size()){
    node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(seen[to] == 0) {
        q.push(to);
        seen[to] = 1;
      }
    }
  }
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0 && (0 < g[i].size() || 0 < self[i]))
     return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int n, m;
  cin >> n >> m;

  int node = 1;
  for(int i = 1;i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if(x != y){
      g[x].push_back(y);
      g[y].push_back(x);
    } else {
      selfloops++;
      self[x] = 1;
    }
    node = x;
  }

  if(isconex(node, n) == 0) {
    cout << 0;
  } else{
    ll result = 1LL * selfloops * (m - selfloops) + 1LL * selfloops * (selfloops - 1) / 2;
    for(int i = 1; i <= n; i++)
      result += 1LL * g[i].size() * (g[i].size() - 1) / 2;
    cout << result;
  }
  return 0;
}