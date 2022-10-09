#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int sum[2 + nmax];

int main()
{
  string s, s2;
  cin >> s >> s2;
  int n = s.size(), m = s2.size();
  s = "#" + s;
  s2 = "#" + s2;
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + s[i] - '0';
  int result = 0;
  int sum1 = 0;
  for(int i = 1;i <= m; i++)
    sum1 += s2[i] - '0';
  for(int i = m;i <= n; i++)
    if((sum[i] - sum[i - m]) % 2 == sum1 % 2)
      result++;
  cout << result;
  return 0;
}