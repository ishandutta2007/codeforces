#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

int const nmax = 2000;
int const modulo = 1000000007;
vector<int> g[5 + nmax];

void creategraph(int n ,int k){
  for(int i = 1 ; i <= n - k + 1 ; i++){
    for(int j = 0 ; j < k ; j++){
      g[i + j].push_back(i + k - j - 1);
    }
  }
}
int seen[5 + nmax];

void bfs(int node){
  queue <int> q;
  seen[node] = 1;
  q.push(node);

  while(0 < q.size()){
    node = q.front();
    q.pop();
    for(int h = 0 ; h < g[node].size() ; h++){
      int to = g[node][h];
      if(seen[to] == 0){
        seen[to] = 1;
        q.push(to);
      }
    }
  }
}

int main()
{
  int n , m , k;
  cin >> n >> m >> k;
  creategraph(n , k);
  int result = 1;
  for(int i = 1 ; i <= n ; i++){
    if(seen[i] == 0){
      bfs(i);
      result = 1LL * result * m % modulo;
    }
  }
  cout << result;
  return 0;
}