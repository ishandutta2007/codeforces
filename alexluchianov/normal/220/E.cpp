#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
ll v[1 + nmax];

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n = 0){
    this->n = n;
    aib.resize(1 + n);
  }
  void update(int x, int val){
    while(x <= n){
      aib[x] += val;
      x += (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result += aib[x];
      x = (x & (x - 1));
    }
    return result;
  }
};

map<int,int> code;

void normalize(int n){
  vector<int> temp;
  for(int i = 1;i <= n; i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];
}

namespace MagicStruct{
  ll inversion = 0;
  int n;
  FenwickTree aib1, aib2;
  void initialize(int n_){
    n = n_;
    aib1 = FenwickTree(n);
    aib2 = FenwickTree(n);
  }

  void insertleft(int val){
    inversion += (aib1.query(n) - aib1.query(val)) + aib2.query(val - 1);
    aib1.update(val, 1);
  }
  void eraseleft(int val){
    aib1.update(val, -1);
    inversion -= (aib1.query(n) - aib1.query(val)) + aib2.query(val - 1);
  }
  void inserright(int val){
    inversion += (aib1.query(n) - aib1.query(val)) + aib2.query(val - 1);
    aib2.update(val, 1);
  }
  void eraseright(int val){
    aib2.update(val, -1);
    inversion -= (aib1.query(n) - aib1.query(val)) + aib2.query(val - 1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  ll k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  normalize(n);
  MagicStruct::initialize(n);
  MagicStruct::insertleft(v[1]);

  int ptr = n + 1;
  ll result = 0;
  while(2 < ptr){
    MagicStruct::inserright(v[ptr - 1]);
    if(k < MagicStruct::inversion) {
      MagicStruct::eraseright(v[ptr - 1]);
      break;
    } else
      ptr--;
  }
  result += n + 1 - ptr;


  for(int i = 2;i <= n; i++){
    if(ptr == i)
      MagicStruct::eraseright(v[ptr++]);
    MagicStruct::insertleft(v[i]);
    while(ptr <= n && k < MagicStruct::inversion)
      MagicStruct::eraseright(v[ptr++]);
    result += n + 1 - ptr;
  }
  cout << result;
  return 0;
}