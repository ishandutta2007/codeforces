#include <iostream>

using namespace std;
#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int result = 0;
  while(1 <= b && 2 <= c){
    b -=1;
    c -= 2;
    result += 3;
  }
  while(1 <= a && 2 <= b){
    a -= 1;
    b -= 2;
    result += 3;
  }
  cout << result << '\n';
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