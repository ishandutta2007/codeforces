#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

class fenwick {
  int *tree;
  int length, max_el;

public:
  fenwick (int size, int mxl) {
    length = size + 5;
    max_el = mxl;
    tree = new int [length + 1];
    for (int i = 0; i <= length; i++) {
      tree[i] = 0;
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= (i & -i)) {
      ans += tree[i];
    }
    return ans;
  }

  void add (int index, int val) {
    int cur = get(index) - get(index - 1);
    int diff = min(val, max_el - cur);
    for (int i = index; i <= length; i += (i & -i)) {
      tree[i] += diff;
    }
  }

  void ptree () {
    for (int i = 1; i <= length; i++) {
      cout << get(i) << " ";
    }
    cout << endl;
  }
};

int main () {
  int dayc, replen, frate, srate, queryc;
  scanf("%d %d %d %d %d", &dayc, &replen, &frate, &srate, &queryc);

  fenwick slow (dayc, srate);
  fenwick fast (dayc, frate);

  for (int i = 0; i < queryc; i++) {
    int query;
    scanf("%d", &query);
    
    if (query == 1) {
      int orderc, day;
      scanf("%d %d", &day, &orderc);

      slow.add(day, orderc);
      fast.add(day, orderc);
    } else {
      int day;
      scanf("%d", &day);

      int ans = slow.get(day - 1) + (fast.get(dayc) - fast.get(day + replen - 1));
      printf("%d\n", ans);
    }
  }
}