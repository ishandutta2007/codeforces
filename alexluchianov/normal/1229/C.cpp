#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const rad = 300;

vector<int> g[1 + nmax];
vector<pair<int,int>> edges;
vector<int> bigger[1 + nmax];

int v[1 + nmax];
int query[1 + nmax];


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    if(y < x)
      swap(x, y);

    g[x].push_back(y);
    g[y].push_back(x);
    edges.push_back({x, y});
    bigger[x].push_back(y);
  }
  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += 1LL * bigger[i].size() * (g[i].size() - bigger[i].size());

  cout << result << '\n';
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++) {
    int a;
    cin >> a;
    result -= 1LL * bigger[a].size() * (g[a].size() - bigger[a].size());

    for(int j = 0; j < bigger[a].size(); j++){
      int val = bigger[a][j];
      result -= 1LL * bigger[val].size() * (g[val].size() - bigger[val].size());

      bigger[val].push_back(a);
      result += 1LL * bigger[val].size() * (g[val].size() - bigger[val].size());
    }
    bigger[a].clear();

    cout << result << '\n';
  }
  return 0;
}