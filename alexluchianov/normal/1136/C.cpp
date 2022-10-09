#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
vector<int> v[5 + nmax * 2];
vector<int> v2[5 + nmax * 2];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n;i++)
    for(int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      v[i + j].push_back(x);
    }
  for(int i = 1; i <= n;i++)
    for(int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      v2[i + j].push_back(x);
    }
  for(int i = 2 ; i <= n + m; i++){
    sort(v[i].begin(), v[i].end());
    sort(v2[i].begin(), v2[i].end());

    if(v[i] != v2[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";

  return 0;
}