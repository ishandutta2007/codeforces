#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo =  1000000007;
int const modulo2 = 1000000009;

struct Hash{
  int hash1;
  int hash2;
  Hash(){
    hash1 = hash2 = 0;
  }
  Hash operator + (int a) {
    Hash result;
    result.hash1 = (1LL * hash1 * (nmax + 1) + a) % modulo;
    result.hash2 = (1LL * hash2 * (nmax + 1) + a) % modulo2;
    return result;
  }
  bool operator < (Hash const &a) const{
    if(hash1 != a.hash1)
      return hash1 < a.hash1;
    else
      return hash2 < a.hash2;
  }
};

vector<int> g[1 + nmax];

map<Hash, int> frec;

ll solve(int n){
  ll result = 0;
  for(int i = 1; i <= n; i++){
    sort(g[i].begin(), g[i].end());
    Hash val;
    for(int h = 0; h < g[i].size(); h++)
      val = val + g[i][h];
    result += frec[val];
    frec[val]++;
  }
  return result;
}

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
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ll result = 0;
  result += solve(n);
  for(int i = 1;i <= n; i++)
    g[i].push_back(i);
  result += solve(n);
  cout << result;
  return 0;
}