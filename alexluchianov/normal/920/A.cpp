#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200;
int dist[1 + nmax];

void solve(){
  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    dist[i] = n;

  for(int i = 1;i <= k; i++) {
    int a;
    cin >> a;
    for(int j = 0; j <= n; j++) {
      if(j < a)
        dist[a - j] = MIN(dist[a - j], j + 1);
      if(a + j <= n)
        dist[a + j] = MIN(dist[a + j], j + 1);
    }
  }

  int smax = 0;
  for(int i = 1;i <= n; i++)
    smax = MAX(smax, dist[i]);
  cout << smax << '\n';
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}