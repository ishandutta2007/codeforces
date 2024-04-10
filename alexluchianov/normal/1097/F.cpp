#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <bitset>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))


int const nmax = 7000;
int const maxsets = 100000;

bitset<1 + nmax> base[1 + nmax];
bitset<1 + nmax> v[1 + maxsets];
bitset<1 + nmax> counter[1 + nmax];

int squarefree[1 + nmax];

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);


  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= nmax; i++)
    for(int j = i; j <= nmax; j += i)
      base[j][i] = 1;

  for(int i = 2; i * i <= nmax; i++)
    for(int j = i * i; j <= nmax; j += i * i)
      squarefree[j] = 1;

  for(int i = 1;i <= nmax; i++)
    for(int j = 1;i * j <= nmax; j++)
      counter[i][i * j] = !squarefree[j];

  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, val;
      cin >> x >> val;
      v[x] = base[val];
    } else if(op == 2){
      int x, y, z;
      cin >> x >> y >> z;
      v[x] = (v[y] ^ v[z]);
    } else if(op == 3){
      int x, y, z;
      cin >> x >> y >> z;
      v[x] = (v[y] & v[z]);
    } else {
      int x, val;
      cin >> x >> val;
      cout << (v[x] & counter[val]).count() % 2;
    }
  }

  return 0;
}