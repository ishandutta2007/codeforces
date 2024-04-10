#include <iostream>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax], v2[1 + nmax];
map<pair<int,int>, int> freq;

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
    if(y < x)
      swap(x, y);
    freq[{x, y}] = 1;
  }

  for(int i = 1;i <= n; i++)
    for(int j = i + 1; j <= n; j++) {
      if(freq[{i, j}] == 0) {
        v[i] = v[j] = 1;
        v2[i] = 1;
        v2[j] = 2;
        cout << "YES\n";
        int result = 2;
        for(int k = 1;k <= n; k++)
          if(v[k] == 0) {
            v2[k] = v[k] = ++result;
          }

        for(int k = 1;k <= n; k++)
          cout << v2[k] << " ";
        cout << '\n';
        for(int k = 1;k <= n; k++)
          cout << v[k] << " ";
        cout << '\n';
        return 0;
      }
    }
  cout << "NO";


  return 0;
}