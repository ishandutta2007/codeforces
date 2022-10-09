#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
char s[5 + nmax];

void solve(){
  ll n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  int last = 0;
  for(int i = 1;i <= n; i++){
    if(s[i] == '0'){
      if(i - (last + 1) <= k) {
        k -= i - (last + 1);
        swap(s[i], s[last + 1]);
        last++;
      } else {
        swap(s[i], s[i - k]);
        k = 0;
      }
    }
  }
  for(int i = 1;i <= n; i++)
    cout << s[i];
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