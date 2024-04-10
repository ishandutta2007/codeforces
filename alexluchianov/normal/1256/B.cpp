#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[5 + nmax];
int used[5 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    used[i] = 0;
  }
  for(int i = 1;i <= n; i++){
    int pos = 1;
    while(v[pos] != i)
      pos++;
    while(1 < pos && used[pos - 1] == 0 && v[pos - 1] > v[pos]){
      swap(v[pos - 1], v[pos]);
      used[pos - 1] = 1;
      pos--;
    }
  }
  for(int i = 1;i <= n; i++)
    cout << v[i] << " " ;
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}