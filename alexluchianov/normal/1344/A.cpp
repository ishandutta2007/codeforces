#include <iostream>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int frec[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 0 ;i < n; i++)
    frec[i] = 0;

  for(int i = 0;i < n; i++){
    int val;
    cin >> val;
    val %= n;
    if(val < 0)
      val += n;
    frec[(i + val) % n]++;
  }
  for(int i = 0; i < n; i++)
    if(frec[i] == 0) {
      cout << "NO\n";
      return ;
    }
  cout << "YES\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}