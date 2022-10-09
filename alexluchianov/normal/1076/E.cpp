#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
vector<int> g[5 + nmax];

struct Query{
  int dist;
  int val;
};

vector<Query> query[5 + nmax];
ll sum[5 + nmax];
ll addsum[5 + nmax];

void dfs(int node , int parent , int level, ll acc) {
  acc += addsum[level];

  for(int h = 0 ; h < query[node].size() ; h++){
    acc += query[node][h].val;
    if(level + query[node][h].dist + 1 <= nmax)
      addsum[level + query[node][h].dist + 1] -= query[node][h].val;
  }
  sum[node] = acc;

  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to , node , level + 1 , acc);
  }

  for(int h = 0 ; h < query[node].size() ; h++){

    if(level + query[node][h].dist + 1 <= nmax)
      addsum[level + query[node][h].dist + 1] += query[node][h].val;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1 ; i < n ; i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int m;
  cin >> m;
  for(int i = 1 ; i <= m ; i++){
    Query q;
    int x;
    cin >> x;
    cin >> q.dist >> q.val;
    query[x].push_back(q);
  }
  dfs(1 , 0 , 1 , 0 );

  for(int i = 1 ; i <= n ; i++)
    cout << sum[i] << " ";

  return 0;
}