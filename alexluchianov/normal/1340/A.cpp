#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax], seen[1 + nmax];
int pos[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    seen[i] = 0;
  }
  seen[0] = seen[n + 1] = 1;
  for(int i = 1;i <= n; i++)
    pos[v[i]] = i;

  int rest = 0;
  for(int i = 1;i <= n; i++){
    int posp = pos[i];
    seen[posp] = 1;
    if(seen[rest] == 1)
      rest = posp + 1;
    else {
      cout << "No\n";
      return ;
    }
  }
  cout << "Yes\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++){
    solve();
  }
  return 0;
}