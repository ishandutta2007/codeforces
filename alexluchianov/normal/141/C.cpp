#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 3000;

struct Person{
  string name;
  int val;
  bool operator < (Person const &a) const {
    return val < a.val;
  }
} v[1 + nmax];
int h[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    cin >> v[i].name >> v[i].val;
  }
  sort(v + 1, v + n + 1);
  for(int i = 1;i <= n; i++)
    if(i <= v[i].val) {
      cout << -1;
      return 0;
    }
  for(int i = 1;i <= n; i++){
    h[i] = i - v[i].val;
    for(int j = 1;j < i; j++)
      if(h[i] <= h[j])
        h[j]++;
  }
  for(int i = 1;i <= n; i++)
    cout << v[i].name << " " << h[i] << '\n';
  return 0;
}