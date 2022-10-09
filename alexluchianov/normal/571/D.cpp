#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int phase;

namespace Dsu{
  int n;
  vector<int> mult;
  vector<int> sz;
  vector<ll> acc;
  vector<ll> bonus;

  int ptr = 0;

  void initialize(int n_){
    n = n_;
    ptr = n;
    mult.resize(1 + 2 * n);
    sz.resize(1 + 2 * n);
    acc.resize(1 + 2 * n);
    bonus.resize(1 + 2 * n);

    for(int i = 1;i <= 2 * n; i++)
      mult[i] = i;
    for(int i = 1;i <= 2 * n; i++)
      sz[i] = 0;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
    for(int i = 1;i <= 2 * n; i++)
      acc[i] = 0;
    for(int i = 1;i <= 2 * n; i++)
      bonus[i] = 0;
  }

  ll combine(ll a, ll b){
    if(phase == 1)
      return max(a, b);
    else
      return a + b;
  }

  int jump(int gala){
    int parent = mult[gala];
    if(gala != parent) {
      mult[gala] = jump(parent);
      acc[gala] = combine(acc[gala], acc[parent]);
    }
    return mult[gala];
  }

  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;

    ++ptr;
    assert(ptr <= 2 * n);

    mult[gala] = ptr;
    mult[galb] = ptr;
    sz[ptr] = sz[gala] + sz[galb];
    acc[galb] = bonus[galb];
    acc[gala] = bonus[gala];
  }

  void update(int gala, int val){
    gala = jump(gala);
    bonus[gala] = combine(bonus[gala], val);
  }

  ll query(int gala){
    jump(gala);
    return combine(acc[gala], bonus[jump(gala)]);
  }
}

struct Update{
  int type;
  int x;
  int y;
  int time;
  int id;
  bool operator < (Update const &a) const{
    if(time != a.time)
      return time < a.time;
    else
      return type < a.type;
  }
};
ll sol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  Dsu::initialize(n);

  vector<Update> updates;

  phase = 1;

  int queries = 0;

  for(int i = 1;i <= m; i++){
    char op;
    cin >> op;
    if(op == 'U'){
      int x, y;
      cin >> x >> y;
      updates.push_back({1, x, y, i, 0});
    } else if(op == 'M'){
      int x, y;
      cin >> x >> y;
      Dsu::unite(x, y);
    } else if(op == 'A'){
      int x;
      cin >> x;
      updates.push_back({2, x, 0, i, 0});
    } else if(op == 'Z'){
      int x;
      cin >> x;
      Dsu::update(x, i);
    } else if(op == 'Q'){
      int x;
      cin >> x;
      ++queries;
      updates.push_back({3, x, -1, Dsu::query(x), queries});
      updates.push_back({3, x, 1, i, queries});
      assert(Dsu::query(x) < i);
    }
  }

  phase = 2;
  sort(updates.begin(), updates.end());
  Dsu::initialize(n);

  for(int i = 0; i < updates.size(); i++){
    if(updates[i].type == 1)
      Dsu::unite(updates[i].x, updates[i].y);
    else if(updates[i].type == 2)
      Dsu::update(updates[i].x, Dsu::sz[Dsu::jump(updates[i].x)]);
    else {
      sol[updates[i].id] += Dsu::query(updates[i].x) * updates[i].y;
    }
  }

  for(int i = 1; i <= queries; i++)
    cout << sol[i] << '\n';
  return 0;
}