#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  if(n == 1 && m == 1) {
    cout << 0;
  } else if(n == 1){
    for(int j = 1;j <= m; j++)
      cout << 1 + j << " ";
    cout << '\n';
  } else if(m == 1){
    for(int i = 1; i <= n; i++)
      cout << 1 + i << '\n';
  } else
    for(int i = 1;i <= n; i++) {
      for(int j = 1;j <= m; j++)
        cout << i * (j + n) << " ";
      cout << '\n';
    }
  return 0;
}