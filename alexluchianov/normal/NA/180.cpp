#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

struct Person{
  int a;
  int b;
  bool operator < (Person const &val) const{
    return (b - a) < (val.b - val .a);
  }
};

Person v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n;i++)
    cin >> v[i].a >> v[i].b;
  sort(v + 1, v + n + 1);
  ll result = 0;
  for(int i = 1;i <= n;i++)
    result += 1LL * (i - 1) * v[i].a + 1LL * (n - i) * v[i].b;
  cout << result;

  return 0;
}