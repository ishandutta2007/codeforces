#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[5 + nmax];

void solve(){
  int n, m, d;
  cin >> n >> m >> d;
  int sum = 0;
  for(int i = 1;i <= m; i++) {
    cin >> v[i];
    sum += v[i];
  }
  int dist = (n - sum) / (m + 1);
  int big = (n - sum) % (m + 1);
  if(d <= dist + (0 < big))
    cout << "No\n";
  else{
    cout << "Yes\n";
    for(int i = 1;i <= m; i++){
      if(0 < big) {
        for(int j = 1;j <= dist + 1; j++)
          cout << 0 << " ";
        big--;
      } else
        for(int j = 1;j <= dist; j++)
          cout << 0 << " ";
      for(int j = 1;j <= v[i]; j++)
        cout << i << " ";
    }
    if(0 < big) {
      for(int j = 1;j <= dist + 1; j++)
        cout << 0 << " ";
      big--;
    } else
      for(int j = 1;j <= dist; j++)
        cout << 0 << " ";
    cout << '\n';
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
  return 0;
}