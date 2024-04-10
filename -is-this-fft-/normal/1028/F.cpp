#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

template<typename T, typename U>
ostream& operator<< (ostream &out, pair<T, U> pr) {
  out << pr.first << " " << pr.second;
  return out;
}

typedef long long llong;
typedef pair<int, int> point;

llong sq (int x) {
  return (llong) x * (llong) x;
}

llong sqnorm (point p) {
  return sq(p.first) + sq(p.second);
}

map<llong, set<point>*> classes;

set<point>* get_class (llong norm) {
  auto it = classes.find(norm);
  if (it == classes.end()) {
    classes[norm] = new set<point>;
    return classes[norm];
  }
  return it->second;
}

llong gcd (llong a, llong b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

map<point, int> decr;
point avg (point p, point q) {
  p.first += q.first;
  p.second += q.second;

  int gc = gcd(p.first, p.second);
  p.first /= gc;
  p.second /= gc;

  return p;
}

int cnt = 0;
void add (point p) {
  set<point> *cur_class = get_class(sqnorm(p));

  if (decr.count(avg(p, p)) != 0) {
    decr[avg(p, p)] += 1;
  }

  for (set<point>::iterator it = cur_class->begin(); it != cur_class->end(); it++) {
    point cur_avg = avg(*it, p);
    if (decr.count(cur_avg) != 0) {
      decr[cur_avg] += 2;
    }
  }

  cur_class->insert(p);
  cnt++;
}

void del (point p) {
  set<point> *cur_class = get_class(sqnorm(p));

  cur_class->erase(p);
  cnt--;
  for (set<point>::iterator it = cur_class->begin(); it != cur_class->end(); it++) {
    point cur_avg = avg(*it, p);
    if (decr.count(cur_avg) != 0) {
      decr[cur_avg] -= 2;
    }
  }

  if (decr.count(avg(p, p)) != 0) {
    decr[avg(p, p)] -= 1;
  }

}

void answer (point p) {
  p = avg(p, p);
  cout << cnt - decr[p] << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int queryc;
  cin >> queryc;

  vector<pair<int, point>> queries (queryc);
  for (int i = 0; i < queryc; i++) {
    cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
    if (queries[i].first == 3) {
      decr[avg(queries[i].second, queries[i].second)] = 0;
    }
  }

  for (pair<int, point> query : queries) {
    if (query.first == 1) {
      add(query.second);
    } else if (query.first == 2) {
      del(query.second);
    } else {
      answer(query.second);
    }
  }
}