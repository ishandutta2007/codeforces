#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000;
int const lgmax = 33;
ll f[1 + lgmax][1 + nmax], w[1 + lgmax][1 + nmax], wmin[1 + lgmax][1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  ll k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> f[0][i];
  for(int i = 0; i < n; i++) {
    cin >> w[0][i];
    wmin[0][i] = w[0][i];
  }

  for(int jump = 1; jump <= lgmax; jump++){
    for(int i = 0;i < n; i++){
      f[jump][i] = f[jump - 1][f[jump - 1][i]];
      w[jump][i] = w[jump - 1][i] + w[jump - 1][f[jump - 1][i]];
      wmin[jump][i] = MIN(wmin[jump - 1][i], wmin[jump - 1][f[jump - 1][i]]);
    }
  }
  for(int i = 0;i < n; i++){
    ll k2 = k;
    ll result = 0, result2 = inf;
    int node = i;

    for(int jump = lgmax; 0 <= jump; jump--){
      if((1LL << jump) <= k2){
        k2 -= (1LL << jump);
        result = result + w[jump][node];
        result2 = MIN(result2, wmin[jump][node]);
        node = f[jump][node];
      }
    }
    cout << result << " " << result2 << '\n';
  }
  return 0;
}