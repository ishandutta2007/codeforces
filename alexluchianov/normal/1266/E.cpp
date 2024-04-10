#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
map<pair<int,int>, int> frec;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    result += v[i];
  }

  int m;
  cin >> m;
  for(int i = 1;i <= m; i++){
    int s, t, u;
    cin >> s >> t >> u;
    if(0 < frec[{s, t}]) {
      v[frec[{s, t}]]++;
      if(0 < v[frec[{s, t}]])
        result++;
    }
    frec[{s, t}] = u;
    v[u]--;
    if(0 <= v[u])
      result--;
    cout << result << '\n';
  }
  return 0;
}