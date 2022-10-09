#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
char v[5 + nmax];
char v2[5 + nmax];

int main()
{
  int n , p;
  cin >> n >> p;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
    v2[i] = v[i];
    if(v[i] == '.')
      v2[i] = '0';
  }

  bool ok = 0;
  for(int i = p + 1 ; i <= n ; i++){
    if(v2[i] != v2[i - p]) {
      ok = 1;
    }else if(v[i] == '.'){
      v2[i] = (1 - (v2[i - p] - '0')) + '0';
      ok = 1;
    } else if(v[i - p] == '.'){
      v2[i - p] = (1 - (v2[i] - '0')) + '0';
      ok = 1;
    }
  }
  if(ok == 1)
    for(int i = 1 ; i <= n ; i++)
      cout << v2[i];
  else
    cout << "NO";

  return 0;
}