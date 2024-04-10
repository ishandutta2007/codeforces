#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int d[1 + nmax];
vector<pair<int,int>> edges;

void addEdge(int x, int y){
  edges.push_back({x, y});
}
int ind[1 + nmax];

bool compare(int x, int y){
  return d[x] > d[y];
}

deque<int> dq;

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> d[i];

  for(int i = 1;i <= n; i++)
    ind[i] = i;
  sort(ind + 1, ind + n + 1, compare);

  for(int i = 1;i <= n;i++)
    dq.push_back(ind[i] * 2 - 1);

  for(int i = 1;i < n; i++)
    addEdge(ind[i] * 2 - 1, ind[i + 1] * 2 - 1);

  for(int i = 1;i <= n; i++){
    if(d[ind[i]] <= i)
      addEdge(ind[(i - d[ind[i]] + 1)] * 2 - 1 , ind[i] * 2);
    else {
      while(d[ind[i]] < dq.size())
        dq.pop_back();

      addEdge(dq.back(), ind[i] * 2);
      dq.push_back(ind[i] * 2);
      dq.pop_front();
    }
  }

  for(int i = 0; i < edges.size(); i++)
    cout << edges[i].first << " " << edges[i].second << '\n';

  return 0;
}