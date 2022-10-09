#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  int st = 1, dr = n, turn = 0;
  ll resultx= 0, resulty = 0;
  while(st <= dr){
    if(turn == 0){
      resultx += v[dr];
      dr--;
    } else {
      resulty += v[st];
      st++;
    }
    turn = !turn;
  }
  cout << 1LL * resultx * resultx + 1LL * resulty * resulty;
  return 0;
}