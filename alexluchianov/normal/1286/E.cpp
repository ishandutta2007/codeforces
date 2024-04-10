#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
using ull = __int128;

class FenwickTree{
  private:
    std::vector<ll> aib;
    int n;
  public:
    FenwickTree(int n_) { 
      n = n_;
      aib.resize(1 + n);
    }
    void update(int pos, ll val) {
      aib[0] += val;
      for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
        aib[x] += val;
    }
    ll query(int pos) {
      ll result = 0;
      for(int x = pos; 0 < x; x = (x & (x - 1)))
        result += aib[x];
      return result;
    }
    void update2(int x, int y, int val) {
      update(x, val);
      update(y + 1, -val);
    }
    ll query2(ll x, ll y) {
      return query(y) - query(x - 1);
    }
    void print() {
      std::cout << "Print\n";
      for(int i = 1; i <= n; i++)
        std::cout << query(i) << " " ;
      std::cout << '\n';
    }
};

int const nmax = 600000;
int const sigma = 26;

char v[1 + nmax];

std::vector<std::pair<int,int>> st;

struct Event{
  int start;
  int l;
  int dist;
  bool operator < (Event const oth) const{
    return start < oth.start;
  }
};

void printlong(ull number) {
  std::string s;
  if(number == 0)
    std::cout << 0 << '\n';
  while(0 < number) {
    s = s + (char)((number % 10) + '0');
    number /= 10;
  }
  std::reverse(s.begin(), s.end());
  std::cout << s << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  FenwickTree points(n), colors(n);

  std::vector<Event> events, newevents;

  int smin = -1;
  
  ull result = 0;
  ll resultmod = 0;
  ll sol = 0;

  for(int i = 1;i <= n; i++) {
    char ch;
    ll val;
    std::cin >> ch >> val;

    ll key = (result & ((1LL << 30) - 1));
    ch = ((ch - 'a') + resultmod) % sigma + 'a';
    val ^= key;
    
    v[i] = ch;

    if(i == 1) {
      st.push_back({i, val});
      colors.update2(i, i, val);
      result += val;
      resultmod = (resultmod + val) % sigma;

      smin = val;
    } else {
      smin = std::min(1LL * smin, 1LL * val);
      result += smin;
      resultmod = (resultmod + smin) % sigma;

      int last = i;
      colors.update2(last, last, val);

      sol += 1LL * val * points.query2(last, last);
      while(0 < st.size() && val < st.back().second) {
        colors.update2(st.back().first, last - 1, val - st.back().second);
        sol += 1LL * (val - st.back().second) * points.query2(st.back().first, last - 1);
        last = st.back().first;
        st.pop_back();
      }
      st.push_back({last, val});

      for(int j = 0; j < events.size(); j++) {
        Event e = events[j];
        if(v[(i - e.start) + 1] == v[i])
          newevents.push_back(e);
        else {
          int pos = e.start;
          for(int h = 0; h < e.l; h++) {
            sol -= colors.query(pos);
            points.update(pos, -1);
            pos += e.dist;
          }
        }
      }

      if(v[1] == v[i]) {
        newevents.push_back({i, 1, 1});
        points.update(i, 1);
        sol += colors.query(i);
      }

      events.clear();

      for(int j = 0; j < newevents.size(); j++) {
        Event e = newevents[j];
        if(0 == events.size()) {
          events.push_back({e.start, 1, nmax});
          if(1 < e.l) 
            events.push_back({e.start + e.dist, e.l - 1, e.dist});
        } else {
          int last = events.back().start + (events.back().l - 1) * events.back().dist;
          if((e.start - last) == e.dist) {
            if(events.back().dist == e.dist)
              events.back().l += e.l;
            else {
              events.push_back(e);
            }
          } else {
            events.push_back({e.start, 1, e.start - last});
            if(1 < e.l)
              events.push_back({e.start + e.dist, e.l - 1, e.dist});
          }
        }
      }
      newevents.clear();
    }
    result += sol;
    resultmod = (resultmod + sol) % sigma;
    printlong(result);
  }
  return 0;
}