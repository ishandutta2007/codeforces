#include <iostream>
#include <algorithm>
#include <queue>

typedef long long llong;

const int MAX_LENGTH = 2005;

using namespace std;

struct elem {
  int val, pos;
  
  elem () {
  }

  elem (int _val, int _pos) {
    val = abs(_val);
    pos = _pos;
  }
};

bool operator< (elem p, elem q) {
  if (p.val == q.val) {
    return p.pos < q.pos;
  } else {
    return p.val < q.val;
  }
}

elem elements [MAX_LENGTH];

class fenwick {
  int *tree, size;

public:
  fenwick (int _size) {
    size = _size;
    tree = new int [size + 5];

    for (int i = 0; i <= size; i++) {
      tree[i] = 0;
    }
  }
  
  void add (int index, int val) {
    for (int i = index; i <= size; i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

int main () {
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    int val;
    cin >> val;
    
    elements[i - 1] = elem(val, i);
  }

  sort(elements, elements + length);

  llong ans = 0;
  queue<int> updates;
  fenwick cnt (length + 5);
  for (int i = 0; i < length; i++) {
    if (i > 0 && elements[i].val != elements[i - 1].val) {
      while (!updates.empty()) {
        cnt.add(updates.front(), 1);
        updates.pop();
      }
    }

    ans += min(cnt.get(elements[i].pos), 
               cnt.get(length + 3) - cnt.get(elements[i].pos));
    updates.push(elements[i].pos);
  }

  cout << ans << endl;
}