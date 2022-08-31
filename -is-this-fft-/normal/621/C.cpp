#include <iostream>
#include <iomanip>

const int MAX_SHARK = 100005;

using namespace std;

long double prob [MAX_SHARK];

int main () {
  int sharkc, fav;
  cin >> sharkc >> fav;

  for (int i = 0; i < sharkc; i++) {
    int left, right;
    cin >> left >> right;
    
    int toosmall = (left - 1) / fav;
    int largest = right / fav;

    prob[i] = ((long double) (largest - toosmall)) /
      ((long double) (right - left + 1)); 
  }

  long double ans = 0;
  for (int i = 0; i < sharkc; i++) {
    long double cprob = 1.0 - ((1.0L - prob[i]) * (1.0L - prob[(i + 1) % sharkc]));
    ans += cprob * 2000.0L;
  }
  
  cout << fixed << setprecision(10) << ans << endl;
}