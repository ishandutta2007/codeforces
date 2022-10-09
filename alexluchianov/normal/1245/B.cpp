#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
char s[1 + nmax];
char sol[1 + nmax];

void solve(){
  int n, a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = 1;i <= n; i++)
    sol[i] = 0;
  int result = 0;
  for(int i = 1;i <= n; i++){
    if(s[i] == 'R' && 0 < b){
      b--;
      result++;
      sol[i] = 'P';
    } else if(s[i] == 'P' && 0 < c){
      c--;
      result++;
      sol[i] = 'S';
    } else if(s[i] == 'S' && 0 < a){
      a--;
      result++;
      sol[i] = 'R';
    }
  }
  if(result < n / 2 + n % 2) {
    cout << "No\n";
    return ;
  }

  for(int i = 1;i <= n; i++)
    if(sol[i] == 0){
      if(0 < a) {
        sol[i] = 'R';
        a--;
      } else if(0 < b) {
        sol[i] = 'P';
        b--;
      } else if(0 < c) {
        sol[i] = 'S';
        c--;
      }
    }
  cout << "Yes\n";
  for(int i = 1;i <= n; i++)
    cout << sol[i];
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
/*
1
2
1 1 0
RR
*/