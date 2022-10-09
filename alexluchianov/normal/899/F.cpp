#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const nmax = 200000;

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }

  int query(int pos){
    int result = 0;
    for(int x = pos; 0 < x; x &= (x - 1))
      result += aib[x];
    return result;
  }

  int lowerthan(int target){
    int x = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2){
      if(x + jump <= n && aib[x + jump] < target) {
        target -= aib[x + jump];
        x += jump;
      }
    }
    return x + 1;
  }
};

char s[1 + nmax];
set<int> freq[1 + nmax];

void event(int x, int y, int val, FenwickTree &aib){
  set<int>::iterator it;
  it = freq[val].lower_bound(x);
  while(it != freq[val].end() && *it <= y){
    aib.update(*it, -1);
    freq[val].erase(it++);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  int ptr = 0;
  map<char,int> id;
  for(char i = 'a'; i <= 'z'; i++)
    id[i] = ++ptr;
  for(char i = 'A'; i <= 'Z'; i++)
    id[i] = ++ptr;
  for(char i = '0'; i <= '9'; i++)
    id[i] = ++ptr;
  FenwickTree aib(n);

  for(int i = 1;i <= n; i++){
    aib.update(i, 1);
    cin >> s[i];
    freq[id[s[i]]].insert(i);
  }

  for(int i = 1;i <= q; i++){
    int x, y;
    char c;
    cin >> x >> y >> c;
    event(aib.lowerthan(x), aib.lowerthan(y), id[c], aib);
  }

  for(int i = 1;i <= n; i++)
    if(aib.query(i) - aib.query(i - 1) == 1)
      cout << s[i];
  return 0;
}