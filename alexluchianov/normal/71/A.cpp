#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++){
    string s;
    cin >> s;
    if(s.size() <= 10)
      cout << s << '\n';
    else
      cout << s[0] << s.size() - 2 << s[s.size() - 1] << '\n';
  }
  return 0;
}