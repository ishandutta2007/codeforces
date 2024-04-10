#include <iostream>
#include <set>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

typedef long long llong;
typedef long double ldouble;

const int MAX_QUERY = 50005;
const int MAX_LENGTH = 500005;
const int INF = 1023456789;

using namespace std;

struct query {
  int type, left, right;
  llong val;
} queries [MAX_QUERY];

struct element {
  int index;
  llong value;

  element () {
    index = -1;
    value = -1;
  }

  element (int _index, llong _value) {
    index = _index;
    value = _value;
  }
};

bool operator< (element p, element q) {
  if (p.value == q.value) {
    return p.index < q.index;
  } else {
    return p.value < q.value;
  }
}

inline int leftmost (llong value, set<element> *segment) {
  set<element>::iterator lb = segment->lower_bound(element(-1, value));
  if (lb == segment->end()) {
    return INF;
  }
  
  if (lb->value == value) {
    return lb->index;
  } else {
    return INF;
  }
}

inline int rightmost (llong value, set<element> *segment) {
  set<element>::iterator lb = segment->lower_bound(element(INF, value));
  if (lb == segment->begin()) {
    return -1;
  }

  lb--;
  if (lb->value == value) {
    return lb->index;
  } else {
    return -1;
  }
}

llong arr [MAX_LENGTH], add [MAX_LENGTH];
bool rebuild [MAX_LENGTH];

int main () {
  ios::sync_with_stdio(false);

  int length, queryc;
  cin >> length >> queryc;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  int modifyqc = 0, getqc = 0;
  for (int i = 0; i < queryc; i++) {
    cin >> queries[i].type;
    
    if (queries[i].type == 1) {
      cin >> queries[i].left >> queries[i].right >> queries[i].val;
      queries[i].right++;

      modifyqc++;
    } else {
      cin >> queries[i].val;

      getqc++;
    }
  }

  llong block_size;
  if (getqc == 0) {
    block_size = length + 100;
  } else {
    block_size = (llong) sqrt(((ldouble) length * (ldouble) modifyqc) /
                              ((ldouble) getqc));
  }
  if (block_size == 0) {
    block_size++;
  }

  int curmq = 0;
  for (int i = 0; i < queryc; i++) {
    if ((queries[i].type == 1) && (curmq % block_size == 0)) {
      rebuild[i] = true;
    }

    if (queries[i].type == 1) {
      curmq++;
    }
  }
  rebuild[0] = true;

  vector<int> cur_delim;
  vector<set<element> > cur_bst;
  for (int i = 0; i < queryc; i++) {
    if (rebuild[i]) {
      /* rebuild arr and add */
      llong cur_cum = 0;
      for (int j = 1; j <= length; j++) {
        cur_cum += add[j];
        arr[j] += cur_cum;
        add[j] = 0;
      }

      /* rebuild cur_delim */
      vector<int> delimiters;
      delimiters.push_back(1);
      delimiters.push_back(length + 1);
      for (int j = i; j < queryc && !(j > i && rebuild[j]); j++) {
        if (queries[j].type == 1) {
          delimiters.push_back(queries[j].left);
          delimiters.push_back(queries[j].right);
        }
      }
      sort(delimiters.begin(), delimiters.end());

      cur_delim = vector<int> (0);
      for (int i = 0; i < (int) delimiters.size(); i++) {
        if (i == 0 || delimiters[i] != delimiters[i - 1]) {
          cur_delim.push_back(delimiters[i]);
        }
      }

      /* rebuild cur_bst */
      cur_bst = vector<set<element> > ((int) cur_delim.size() - 1);
      for (int j = 0; j < (int) cur_bst.size(); j++) {
        for (int k = cur_delim[j]; k < cur_delim[j + 1]; k++) {
          cur_bst[j].insert(element(k, arr[k]));
        }
      }
    }

    if (queries[i].type == 1) {
      add[queries[i].left] += queries[i].val;
      add[queries[i].right] -= queries[i].val;
    } else if (queries[i].type == 2) {
      llong cur_cum = 0;
      int lefte = INF, righte = -1;

      for (int j = 0; j < (int) cur_bst.size(); j++) {
        cur_cum += add[cur_delim[j]];
        lefte = min(lefte, leftmost(queries[i].val - cur_cum, &cur_bst[j]));
        righte = max(righte, rightmost(queries[i].val - cur_cum, &cur_bst[j]));
      }

      if (righte - lefte < 0) {
        printf("-1\n");
      } else {
        printf("%d\n", righte - lefte);
      }
    }
  }
}