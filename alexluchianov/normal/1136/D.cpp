#include <iostream>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax];

map<pair<int,int>, int> frec;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    frec[{x, y}] = 1;
  }
  int last = v[n];
  for(int i = n - 1;1 <= i; i--){
    if(frec[{v[i], last}] == 1){
      int pos = i;
      bool op = 0;
      while(pos < n && frec[{v[pos], v[pos + 1]}]) {
        swap(v[pos], v[pos + 1]);
        pos++;
      }
    }
  }
  for(int i = 1;i <= n; i++)
    if(v[i] == last)
      cout << n - i;
  return 0;
}