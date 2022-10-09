#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int seen[1 + nmax];

void solve(){
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= 3 * n; i++)
    seen[i] = 0;
  int matching = 0;
  vector<int> edges;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    if(seen[x] == 0 && seen[y] == 0) {
      seen[x] = seen[y] = 1;
      matching++;
      edges.push_back(i);
    }
  }

  if(n <= matching){
    cout << "Matching\n";
    for(int i = 0; i < n; i++)
      cout << edges[i] << " ";
    cout << '\n';
  } else {
    cout << "IndSet\n";
    int result = n;
    for(int i = 1;i <= 3 * n; i++)
      if(seen[i] == 0) {
        cout << i << " ";
        result--;
        if(result == 0 )
          break;
      }
    cout << '\n';
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}