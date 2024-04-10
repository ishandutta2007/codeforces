#include <iostream>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400000;

using ll = long long;
map<int,int> id;
int ptr = 0;

namespace Dsu{
  int mult[1 + nmax], farp[1 + nmax], sz[1 + nmax];

  void addnode(int node){
    mult[node] = node;
    sz[node] = 1;
    farp[node] = 0;
  }

  int jump(int node){
    if(node != mult[node]){
      int parent = mult[node];
      jump(parent);
      mult[node] = mult[parent];
      farp[node] ^= farp[parent];
    }
    return mult[node];
  }

  void unite(int gala, int galb, int cost){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    sz[galb] += sz[gala];
    mult[gala] = galb;
    farp[gala] = cost;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int q, last = 0;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int l, r, val;
      cin >> l >> r >> val;
      l ^= last;
      r ^= last;
      val ^= last;
      if(r < l)
        swap(l, r);
      r++;
      if(id[l] == 0){
        id[l] = ++ptr;
        Dsu::addnode(ptr);
      }
      if(id[r] == 0){
        id[r] = ++ptr;
        Dsu::addnode(ptr);
      }
      l = id[l];
      r = id[r];

      Dsu::jump(l);
      Dsu::jump(r);
      if(Dsu::mult[l] == Dsu::mult[r])
        continue;
      else
        Dsu::unite(l, r, Dsu::farp[l]^Dsu::farp[r]^val);

    } else {
      int l, r;
      cin >> l >> r;
      l ^= last;
      r ^= last;
      if(r < l)
        swap(l, r);
      r++;
      if(0 < id[l] && 0 < id[r]){
        l = id[l];
        r = id[r];
        Dsu::jump(l);
        Dsu::jump(r);

        if(Dsu::mult[l] == Dsu::mult[r]) {
          last = Dsu::farp[l] ^ Dsu::farp[r];
          cout << last << '\n';
        } else {
          cout << -1 << '\n';
          last = 1;
        }
      } else {
        cout << -1 << '\n';
        last = 1;
      }
    }
  }
  return 0;
}