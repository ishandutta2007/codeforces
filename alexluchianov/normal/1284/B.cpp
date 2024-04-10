#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax];
int frecmin[1 + nmax], frecmax[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int l;
    cin >> l;
    bool decreasing = 1;
    for(int j = 1;j <= l; j++)
      cin >> v[j];
    for(int j = 2;j <= l; j++)
      if(v[j - 1] < v[j])
        decreasing = 0;
    if(decreasing == 1){
      frecmax[v[1]]++;
      frecmin[v[l]]++;
    }
  }
  ll result = 0, sum = 0;
  for(int i = 0;i <= nmax; i++){
    sum += frecmax[i];
    result += frecmin[i] * sum;
  }
  cout << 1LL * n * n - result << '\n';
  return 0;
}