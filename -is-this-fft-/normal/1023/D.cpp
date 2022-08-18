#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 200005;

int l [MAX_N], r [MAX_N];
int arr [MAX_N];
int new_arr [MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    l[i] = MAX_N;
    r[i] = -1;
  }
  
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> elems;
  for (int i = 0; i < length; i++) {
    if (arr[i] != 0) {
      elems.push_back(make_pair(arr[i], i));
    }
  }

  sort(elems.begin(), elems.end());
  
  set<int> taken;
  taken.insert(-1);
  taken.insert(length);
  for (pair<int, int> elem : elems) {
    int ub = *taken.lower_bound(elem.second);
    r[elem.first] = max(r[elem.first], ub - 1);

    int lb = *prev(taken.lower_bound(elem.second));
    l[elem.first] = min(l[elem.first], lb + 1);

    taken.insert(elem.second);
  }

  deque<pair<int, pair<int, int>>> events;
  bool flag = false;
  for (int i = 1; i <= queryc; i++) {
    if (r[i] != -1) {
      events.push_back(make_pair(l[i], make_pair(i, 0)));
      events.push_back(make_pair(r[i] + 1, make_pair(i, 1)));
    }

    if (r[i] == -1 && i == queryc) {
      flag = true;
    }
  }

  sort(events.begin(), events.end());
  
  set<int> cur;
  for (int i = 0; i < length; i++) {
    while (!events.empty() && events[0].first == i) {
      if (events[0].second.second == 0) {
        cur.insert(events[0].second.first);
      } else {
        cur.erase(events[0].second.first);
      }
      events.pop_front();
    }

    if (cur.empty()) {
      new_arr[i] = queryc;
    } else {
      new_arr[i] = *cur.rbegin();
    }
  }

  for (int i = 0; i < length; i++) {
    if (arr[i] != new_arr[i] && arr[i] != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  if (flag) {
    for (int i = 0; i < length; i++) {
      if (arr[i] == 0) {
        new_arr[i] = queryc;
        flag = false;
        break;
      }
    }
  }

  if (flag) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < length; i++) {
    cout << new_arr[i] << " ";
  }
  cout << endl;
}