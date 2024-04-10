#include <iostream>
#include <algorithm>
#include <cassert>

typedef long long llong;

const int MAX_LEN = 1 << 17;
const int MAX_BIT = 40;

using namespace std;

llong arr [MAX_LEN];

struct slice {
  llong val;
  int id;

  slice () {
    val = 0;
    id = -1;
  }

  slice (llong _val) {
    val = _val;
    id = -1;
  }
} suffix [MAX_LEN];

slice operator^ (slice p, llong q) {
  slice ans;
  ans.val = p.val ^ q;
  ans.id = p.id - 1;
  return ans;
}

bool operator< (slice p, slice q) {
  if (p.val == q.val) {
    return p.id > q.id;
  } else {
    return p.val > q.val;
  }
}

class custom_dsu {
  int *root, size;
  slice *val;

public:
  custom_dsu (int _size) {
    size = _size;

    root = new int [size];
    for (int i = 0; i < size; i++) {
      root[i] = i;
    }

    val = new slice [size];
    for (int i = 0; i < size; i++) {
      val[i] = slice();
    }
  }

  int find (int vertex) {
    if (root[vertex] == vertex) {
      return vertex;
    } else {
      root[vertex] = find(root[vertex]);
      return root[vertex];
    }
  }

  void merge (int child, int parent) {
    if (find(child) != find(parent)) {
      root[find(child)] = find(parent);
    }
  }

  void set_val (int index, slice value) {
    val[index] = value;
  }

  slice get_val (int index) {
    return val[find(index)];
  }

  int search (llong value) { /* first i where val[i] is less than value */
    int ans = 0;
    for (int i = size / 2; i != 0; i /= 2) {
      if (get_val(ans + i).val >= value) {
        ans += i;
      }
    }
    ans++;

    if (get_val(0).val < value) {
      ans = 0;
    }

    return ans;
  }
};

int loc [MAX_LEN];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  suffix[length - 1].val = arr[length - 1];
  suffix[length - 1].id = length - 1;
  for (int i = length - 2; i >= 0; i--) {
    suffix[i] = suffix[i + 1] ^ arr[i];
  }

  sort(suffix, suffix + length);

  for (int i = 0; i < length; i++) {
    loc[suffix[i].id] = i;
  }

  custom_dsu order (MAX_LEN);
  for (int i = 0; i < MAX_LEN; i++) {
    order.set_val(i, suffix[i]);
  }

  llong ans = suffix[0].val, prefix = 0;
  for (int i = 0; i < length; i++) {
    prefix ^= arr[i];
    order.merge(loc[i], loc[i] + 1);

    int left = 0, right = MAX_LEN;
    llong cur_a = 0;
    for (int j = MAX_BIT; j >= 0; j--) {
      cur_a ^= 1LL << j;
      int split = order.search(cur_a);

      if (prefix & 1LL << j) {
        /* we want 0 there -> split is the first */
        if (split < right) {
          left = split;
          cur_a ^= 1LL << j;
        }
      } else {
        /* we want 1 there -> split should be out of range */
        if (split <= left) {
          cur_a ^= 1LL << j;
        } else {
          right = split;

          if (split == MAX_LEN) {
            cur_a ^= 1LL << j;
          }
        }
      }
    }

    ans = max(ans, order.get_val(left).val ^ prefix);
  }

  cout << ans << endl;
}