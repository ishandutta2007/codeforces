#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int pref[1 + nmax];
int used[1 + nmax];
int v[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    used[i] = 0;
  for(int i = 1;i <= n; i++)
    v[i] = 0;

  for(int i = 1;i <= n; i++)
    cin >> pref[i];

  int ptr = 1;
  for(int i = 1;i <= n; i++){
    if(pref[i - 1] < pref[i]) {
      if(used[v[i]] == 0) {
        v[i] = pref[i];
        used[v[i]] = 1;
      } else {
        cout << -1 << '\n';
        return ;
      }
    } else {
      while(ptr <= n && used[ptr] == 1)
        ptr++;
      used[ptr] = 1;
      v[i] = ptr;
      if(pref[i] < v[i]) {
        cout << -1 << '\n';
        return ;
      }
    }
  }
  for(int i = 1;i <= n; i++)
    cout << v[i] << " ";
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