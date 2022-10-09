#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[5 + nmax];
int seen[5 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  priority_queue<int , vector<int>, greater<int> > pq;
  pq.push(1);
  seen[1] = 1;
  while(0 < pq.size()){
    int node = pq.top();
    pq.pop();

    cout << node << " ";
    for(int h = 0 ; h < g[node].size() ; h++){
      int to = g[node][h];
      if(seen[to] == 0){
        seen[to] = 1;
        pq.push(to);
      }
    }
  }

  return 0;
}