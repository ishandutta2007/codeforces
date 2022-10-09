#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
map<int, int> frec;
int v[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n ;i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  int uno = 0;
  for(int i = 2;i <= n; i++){
    if(v[i - 1] == v[i]){
      v[i - 1]--;
      if(uno == 1 || v[i] == 0) {
        cout << "cslnb\n";
        return 0;
      }
      if(1 <= i - 2 && v[i - 2] == v[i - 1]){
        cout << "cslnb\n";
        return 0;
      }
      uno = 1;
    }
  }
  ll result = - (1LL * n * (n - 1) / 2);
  for(int i = 1;i <= n; i++)
    result += v[i];
  result += uno;

  if(result % 2 == 0)
    cout << "cslnb\n";
  else
    cout << "sjfnb\n";

  return 0;
}