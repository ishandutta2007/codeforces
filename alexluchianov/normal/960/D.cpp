#include <iostream>

using namespace std;

#define ll long long

int const nmax = 60;
ll from[1 + nmax], to[1 + nmax];
ll shift[1 + nmax];

ll level(ll node){
  for(int i = 0; i <= 60; i++)
    if(from[i] <= node && node <= to[i])
      return i;
  return 61;
}

void shiftlevel(int lv, ll x){
  shift[lv] = (shift[lv] + x) % (to[lv] - from[lv] + 1);
  if(shift[lv] < 0)
    shift[lv] += (to[lv] - from[lv] + 1);
}

int main()
{
  int q;
  cin >> q;
  from[0] = to[0] = 1;
  for(int i = 1;i <= 60; i++){
    from[i] = from[i - 1] * 2;
    to[i] = to[i - 1] * 2 + 1;
  }
  for(int i = 1;i <= q; i++){
    int t;
    cin >> t;
    if(t == 1){
      ll node, x, lv;
      cin >> node >> x;

      lv = level(node);
      shiftlevel(lv, x);
    } else if(t == 2){
      ll node, x, lv;
      cin >> node >> x;
      lv = level(node);

      while(lv <= 60){
        shiftlevel(lv, x);
        lv++;
        x = x * 2;
      }

    } else if(t == 3){
      ll node, lv;
      cin >> node;
      lv = level(node);
      node = from[lv] + ((to[lv] + from[lv] + 1) + node - from[lv] + shift[lv]) % (to[lv] - from[lv] + 1);

      while(1 <= node){
        cout << from[lv] + ((to[lv] + from[lv] + 1) + node - from[lv] - shift[lv]) % (to[lv] - from[lv] + 1) << " ";
        node = node / 2;
        lv--;
      }
      cout << '\n';
    }
  }
  return 0;
}