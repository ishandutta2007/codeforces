#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const inf = 1000000000;

class Magic{
  private:
    ll offset;
    int sign;
    std::set<ll> myset;

    int active;
    int l, r;
  public:
    Magic(int l_, int r_) {
      if(l_ <= r_) 
        active = 1;
      else
        active = 0;
      l = l_;
      r = r_;

      offset = 0;
      sign = 1;
    }

    void reset(int l_, int r_) {
      if(l_ <= r_)
        active = 1;
      else
        active = 0;
      l = l_;
      r = r_;

      offset = 0;
      sign = 1;
      myset.clear();
    }

    int size() {
      return myset.size();
    }

    bool kaput() {
      return active | size();
    }

    int extract() {
      if(sign == 1)
        return *myset.rbegin() + offset;
      else
        return (*myset.begin()) * -1 + offset;
    }

    void pop() {
      std::set<ll>::iterator it;
      if(sign == 1) {
        it = myset.end();
        it--;
        myset.erase(it);
      } else {
        it = myset.begin();
        myset.erase(it);
      }
    }

    void cleartop(int val) {
      if(active == 1)
        if(val < r) {
          r = val;
          if(r < l)
            active = 0;
        }
      while(0 < size() && val < extract())
        pop();
    }

    bool find(int val) {
      if(active == 1) 
        if(l <= val && val <= r)
          return 1;
      if(sign == 1)
        return myset.find(val - offset) != myset.end();
      else
        return myset.find(-val + offset) != myset.end();
    }


    void transform(int val) {
      if(active == 1) {
        int a = l, b = r;
        l = val - b;
        r = val - a;
      }
      sign = sign * -1;
      offset = val - offset;
    }

    void insert(int val) {
      if(sign == 1)
        myset.insert(val - offset);
      else
        myset.insert(-val + offset);
    }

    void print() {
      std::cout << "Print\n";
      if(active == 1) {
        std::cout << l << "->" << r << ": ";
      }
      for(std::set<ll>::iterator it = myset.begin(); it != myset.end(); it++)
        std::cout << offset + sign * (*it) << " ";
      std::cout << '\n';

    }
};

int const nmax = 500000;
int v[1 + nmax];


void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];

  int smin = 1;
  Magic magic(1, 0), magic2(1, inf);

  for(int i = 1;i <= n; i++) {
    if(v[i] % 2 == 1) {
      smin++;
      if(magic.kaput() == 0) {
        magic2.cleartop(v[i] - 1);
        magic2.transform(v[i]);
      } else
        magic2.reset(1, v[i] - 1);
      magic.cleartop(v[i] - 1);
      magic.transform(v[i]);
      if(magic.kaput() == 0 && magic2.kaput() == 0) {
        smin++;
        magic2.reset(1, v[i] - 1);
      }
    } else {
      int target = v[i] / 2;
      if(magic.find(target)) {
        magic2.reset(1, 0);
        std::swap(magic, magic2);
        magic2.cleartop(v[i] - 1);
        magic2.transform(v[i]);
        magic.insert(target);
      } else if(magic2.find(target)) {
        smin++;
        if(magic.kaput() == 0) {
          magic2.cleartop(v[i] - 1);
          magic2.transform(v[i]);
        } else
          magic2.reset(1, v[i] - 1);
        magic.cleartop(v[i] - 1);
        magic.transform(v[i]);

        magic.insert(target);
      } else {
        smin++;
        int where = 2;
        if(magic.kaput() == 1)
          where = 1;

        magic.cleartop(v[i] - 1);
        magic.transform(v[i]);
        magic2.cleartop(v[i] - 1);
        magic2.transform(v[i]);

        if(where == 2)
          magic2.insert(target);
        else if(where == 1)
          magic.insert(target);
      }
    }
     /*
     std::cout << "phase : " << i << " " << v[i] << " " << smin << '\n';
       magic.print();
       magic2.print();
       std::cout << '\n';
     */

  }

  if(magic.kaput() == 0 && magic2.kaput() == 0)
    std::cout << smin + 1 << '\n';
  else if(magic.kaput() == 0)
    std::cout << smin << '\n';
  else
    std::cout << smin - 1 << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}