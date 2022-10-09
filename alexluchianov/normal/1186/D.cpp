#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
double v[1 + nmax];

double dist(double a, double b){
  return fabs(a - b);
}

int main()
{
  int n;
  cin >> n;
  ll sum = 0;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    sum += int(v[i]);
  }
  for(int i = 1;i <= n; i++){
    if(sum == 0)
      cout << int(v[i]) << '\n';
    else if(sum < 0){
      if(dist(int(v[i]) + 1, v[i]) < 1) {
        sum++;
        cout << int(v[i]) + 1 << '\n';
      } else
        cout << int(v[i]) << '\n';
    } else{
      if(dist(int(v[i]) - 1, v[i]) < 1) {
        sum--;
        cout << int(v[i]) - 1 << '\n';
      } else
        cout << int(v[i]) << '\n';
    }
  }
  return 0;
}