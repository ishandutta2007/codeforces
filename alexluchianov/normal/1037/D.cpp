#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long

int const nmax = 200000;
vector<int> g[1 + nmax];
int sol[1 + nmax];
int inv[1 + nmax];
int sol2[1 + nmax], sol2p = 0;

int seen[1 + nmax];

bool compare(int x, int y){
  return inv[x] < inv[y];
}

void bfs(int node){
  queue<int> q;
  q.push(1);
  seen[1] = 1;

  while(0 < q.size()){
    node = q.front();
    q.pop();
    sol2[++sol2p] = node;
    vector<int> q2;
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(seen[to] == 0) {
        q2.push_back(to);
        seen[to] = 1;
      }
    }
    sort(q2.begin(), q2.end(), compare);
    for(int i = 0; i < q2.size(); i++)
      q.push(q2[i]);
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++) {
    cin >> sol[i];
    inv[sol[i]] = i;
  }
  bfs(sol[1]);
  for(int i =1;i <= n; i++)
    if(sol[i] != sol2[i]) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}