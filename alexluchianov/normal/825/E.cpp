#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 100000;
vector<int> invg[1 + nmax];
int degree[1 + nmax];
int marker[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    invg[y].push_back(x);
    degree[x]++;
  }
  for(int i = 1;i <= n; i++) {
    invg[0].push_back(i);
    degree[i]++;
  }
  priority_queue<int> pq;
  int ptr = n + 1;
  pq.push(0);

  while(0 < pq.size()){
    int node = pq.top();
    pq.pop();
    marker[node] = ptr--;
    for(int h = 0; h < invg[node].size(); h++){
      int to = invg[node][h];
      degree[to]--;
      if(degree[to] == 0){
        pq.push(to);
      }
    }
  }
  for(int i = 1;i <= n; i++)
    cout << marker[i] << " ";
  return 0;
}