#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for(int testcase = 1 ; testcase <= t ; testcase++){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
      cin >> v[i];
    sort(v + 1 , v + n + 1);
    double sol = 1LL * nmax * nmax * 5;
    int soli = 0 , solj = 0;
    int smax = 0;
    for(int i = 1 ; i <= n ; i++){
      if(v[i - 1] == v[i]){

        if(0 < smax){
          double result = (v[i] * 2 + smax * 2);
          result = result * result / (v[i] * smax);
          if(result < sol){
            sol = result;
            soli = smax;
            solj = v[i];
          }
        }

        smax = v[i];
        i++;
      }
    }
    cout << soli << " " << soli << " " << solj << " " << solj << '\n';
  }
  return 0;
}