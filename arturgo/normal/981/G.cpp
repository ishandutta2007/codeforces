#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int INF = 2000 * 1000 * 1000;

class interval_compression {
private:
  map<int, int> events;
public:
  interval_compression();
  void add_interval(int begin, int end);
  vector<pair<int, int>> get_intervals(int begin = -INF, int end = INF);
};


vector<pair<int, int>> interval_complement(const vector<pair<int, int>>& intervals, int begin = -INF, int end = INF) {
  if(intervals.empty()) {
    return {make_pair(begin, end)};
  }

  vector<pair<int, int>> res;
  if(begin != intervals[0].first)
    res.push_back({begin, intervals[0].first});

  for(size_t iInter = 0;iInter < intervals.size() - 1;iInter++)
    res.push_back({intervals[iInter].second, intervals[iInter + 1].first});

  if(end != intervals.back().second)
    res.push_back({intervals.back().second, end});

  return res;
}

const int MOD = 998244353;
interval_compression intervals[200*1000];

long long sommes[(1 << 19)];
pair<long long, long long> fonctions[(1 << 19)];

void push(int n, int np, int d, int f) {
  sommes[np] = (fonctions[n].first * sommes[np] + fonctions[n].second * (f - d)) % MOD;
  fonctions[np] = {(fonctions[n].first * fonctions[np].first) % MOD, (fonctions[n].first * fonctions[np].second + fonctions[n].second) % MOD};
}
void applique(int deb, int fin, pair<long long, long long> func, int n = 1, int d = 0, int f = (1 << 18)) {
  if(deb >= f || d >= fin)
    return;

  int m = (d + f) / 2;
  if(n < (1 << 18)) {
    push(n, 2*n, d, m);
    push(n, 2*n+1, m, f);
    fonctions[n] = {1, 0};
    sommes[n] = (sommes[2 * n] + sommes[2 * n + 1]) % MOD;
  }
  
  if(deb <= d && f <= fin) {
    fonctions[n] = func;
    sommes[n] = func.first * sommes[n] + func.second * (f - d);
    return;
  }

  applique(deb, fin, func, 2 * n, d, m);
  applique(deb, fin, func, 2 * n + 1, m, f);

  sommes[n] = (sommes[2 * n] + sommes[2 * n + 1]) % MOD;
}

int sommeEntre(int deb, int fin, int n = 1, int d = 0, int f = (1 << 18)) {
  if(deb >= f || d >= fin)
    return 0;

  int m = (d + f) / 2;
  if(n < (1 << 18)) {
    push(n, 2*n, d, m);
    push(n, 2*n+1, m, f);
    fonctions[n] = {1, 0};
    sommes[n] = (sommes[2*n] + sommes[2*n+1]) % MOD;
  }

  if(deb <= d && f <= fin) {
    return sommes[n];
  }

  int somme = sommeEntre(deb, fin, 2 * n, d, m) + sommeEntre(deb, fin, 2 * n + 1, m, f);
  return somme % MOD;
}

int main() {
  int nbSlots, nbReqs;
  scanf("%d%d", &nbSlots, &nbReqs);

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int type, deb, fin;
    scanf("%d%d%d", &type, &deb, &fin);

    if(type == 1) {
      int arg;
      scanf("%d", &arg);
      arg--;

      vector<pair<int, int>> arg_present = intervals[arg].get_intervals(deb - 1, fin);
      for(pair<int, int> present : arg_present) {
        applique(present.first, present.second, {2, 0});
      }

      vector<pair<int, int>> arg_absent = interval_complement(arg_present, deb - 1, fin);
      for(pair<int, int> absent : arg_absent) {
	applique(absent.first, absent.second, {1, 1});
      }
      
      intervals[arg].add_interval(deb - 1, fin);
    }
    else {
      printf("%d\n", sommeEntre(deb - 1, fin));
    }
  }
  return 0;
}


interval_compression::interval_compression() {
}

void interval_compression::add_interval(int begin, int end) {
  auto it = events.lower_bound(begin);

  while(it != events.end() && it->first <= end) {
    events.erase(it);
    it = events.lower_bound(begin);
  }

  auto b = events.lower_bound(begin);

  bool shouldBegin = true;
  if(b != events.begin()) {
    b--;
    if(b->second == 1)
      shouldBegin = false;
  }

  if(shouldBegin)
    events[begin] = 1;

  auto f = events.lower_bound(end);
  bool shouldEnd = true;
  if(f != events.end()) {
    if(f->second == -1)
      shouldEnd = false;
  }

  if(shouldEnd)
    events[end] = -1;
}

vector<pair<int, int>> interval_compression::get_intervals(int begin, int end) {
  pair<int, int> cur;
  
  vector<pair<int, int>> res;

  auto begin_it = events.lower_bound(begin);
  
  if(begin_it == events.end())
    return res;

  while(begin_it->second == -1)
    begin_it--;

  auto end_it = events.upper_bound(end);
  if(end_it != events.end())
    end_it++;
  
  auto it = begin_it;
  while(it != end_it) {
    if(it->second == 1) {
      cur.first = max(begin, it->first);
    }
    else {
      cur.second = min(end, it->first);
      if(cur.first != cur.second)
	res.push_back(cur);
    }

    it++;
  }

  return res;
}