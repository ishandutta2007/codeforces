#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int const sigma = 26;
vector<int> g[1 + nmax];
int level[1 + nmax];
int start[1 + nmax], stop[1 + nmax], ptr = 0;
vector<int> frec[1 + nmax][1 + sigma];
char v[1 + nmax];

void dfs(int node){
  start[node] = ++ptr;
  frec[level[node]][v[node] - 'a'].push_back(ptr);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    level[to] = level[node] + 1;
    dfs(to);
  }
  stop[node] = ptr;
}

int lowerthan(vector<int> &val, int target){ ///first position bigger than target
  int x = 0;
  for(int h = 20; 0 <= h; h--){
    if(x + (1 << h) <= val.size() && val[x + (1 << h) - 1] <= target)
      x += (1 << h);
  }
  return x;
}

string solve(){
  int node, h;
  cin >> node >> h;

  int odd = 0;
  for(int ch = 0; ch < 26; ch++) {

    int result = lowerthan(frec[h][ch], stop[node]) - lowerthan(frec[h][ch], start[node] - 1);
    odd += result % 2;
  }
  if(odd <= 1)
    return "Yes";
  else
    return "No";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 2;i <= n; i++){
    int a;
    cin >> a;
    g[a].push_back(i);
  }
  for(int i = 1;i <= n; i++)
    cin >> v[i];

  level[1] = 1;
  dfs(1);

  for(int i = 1;i <= q; i++)
    cout << solve() << '\n';
  return 0;
}