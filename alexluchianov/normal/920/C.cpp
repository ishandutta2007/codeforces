#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[5 + nmax];
char s[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i < n; i++)
    cin >> s[i];

  int last = 0;
  s[n] = '0';
  for(int i = 1;i <= n; i++){
    if(s[i] == '0'){
      sort(v + last + 1, v + i + 1);
      last = i;
    }
  }
  for(int i = 2;i <= n; i++)
    if(v[i - 1] > v[i]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
/*
7
1 2 5 3 4 6 7
011101
*/