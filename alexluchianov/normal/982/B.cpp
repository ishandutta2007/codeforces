#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int const nmax = 200000;

struct Pas{
  int x;
  int pos;
  bool operator < (Pas const &a) const{
    return x < a.x;
  }
};
Pas v[5 + nmax];

stack < Pas > v2;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    cin >> v[i].x;
    v[i].pos = i;
  }
  sort(v + 1 , v + n + 1);
  char c;
  int p = 0;
  for(int i = 1 ; i <= n * 2;i++){
    cin >> c;
    if(c == '1'){
      cout << v2.top().pos << " ";
      v2.pop();
    } else{
      v2.push(v[++p]);
      cout << v2.top().pos << " ";
    }
  }
  return 0;
}