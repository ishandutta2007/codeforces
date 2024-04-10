#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  string s, s2, sfinal;
  cin >> s >> s2 >> sfinal;
  s += s2;
  sort(s.begin(), s.end());
  sort(sfinal.begin(), sfinal.end());
  if(s == sfinal)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}