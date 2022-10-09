#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
char v[1 + nmax];

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] == '(')
      sum++;
    else if(v[i] == ')')
      sum--;
    if(sum < -1) {
      cout << "No";
      return 0;
    }
  }
  if(sum == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}