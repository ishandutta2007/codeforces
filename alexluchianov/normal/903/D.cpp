#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;
#define bulaneala long double

int const nmax = 200000;
map<bulaneala , bulaneala> frec;

int main()
{
  int n;
  cin>>n;
  bulaneala sum = 0;
  bulaneala result = 0;
  bulaneala a;
  for(int i = 1 ; i <= n ;i++){
    cin>>a;
    frec[a]++;
    sum += a;
    int x = frec[a - 1];
    int y = frec[a];
    int z = frec[a + 1];
    result += a * (i - (x + y + z)) - (sum - x * (a - 1) - y * a - z * (a + 1));
  }
  cout<< setprecision(0) << fixed << result;
  return 0;
}