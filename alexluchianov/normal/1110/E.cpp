#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 100000;
int v1[1 + nmax], v2[1 + nmax];

int main()
{
  int n;
  cin >> n;
  vector<int> dif1, dif2;
  for(int i = 1; i <= n; i++)
    cin >> v1[i];
  for(int i = 1; i <= n; i++)
    cin >> v2[i];
  for(int i = 1; i < n; i++)
    dif1.push_back(v1[i + 1] - v1[i]);
  for(int i = 1; i < n; i++)
    dif2.push_back(v2[i + 1] - v2[i]);
  sort(dif1.begin(), dif1.end());
  sort(dif2.begin(), dif2.end());
  if(v1[1] != v2[1] || v1[n] != v2[n]){
    cout << "No";
    return 0;
  }
  for(int i = 0; i < dif1.size(); i++)
    if(dif1[i] != dif2[i]) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}