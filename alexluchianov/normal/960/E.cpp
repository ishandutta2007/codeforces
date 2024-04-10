#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 1000000007;

vector<int> g[1 + nmax];
int v[1 + nmax];
int odd[1 + nmax], even[1 + nmax], sz[1 + nmax];

void dfs(int node, int parent){
  odd[node] = 1;
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent){
      dfs(to, node);
      odd[node] += even[to];
      even[node] += odd[to];
      sz[node] += sz[to];
    }
  }
}

ll result = 0;
int n;

void dfs2(int node, int parent, int accodd, int acceven){
  ll result2 = 0;
  result2 += 1LL * sz[node] * (accodd - acceven) % modulo;
  result2 += n;
  result2 %= modulo;


  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      int oth = (n - sz[to]);
      result2 += 1LL * oth * (even[to] - odd[to]) % modulo;
      result2 %= modulo;

      dfs2(to, node, acceven + even[node] - odd[to], accodd + odd[node] - even[to]);
    }
  }

  result = (result + 1LL * result2 * v[node]) % modulo;
}

int main()
{
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  dfs2(1, 0, 0, 0);

  cout << (modulo + result) % modulo;
  return 0;
}