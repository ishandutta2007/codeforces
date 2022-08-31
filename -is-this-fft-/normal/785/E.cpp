#include <iostream>

typedef long long llong;

const int BLOCK = 450;
const int MAX_SIZE = 200005;

using namespace std;

class fenwick {
  int *tree, size;

public:
  fenwick () {
    size = MAX_SIZE;
    tree = new int [size + 5];

    for (int i = 0; i < size + 5; i++) {
      tree[i] = 0;
    }

  }

  fenwick (int _size) {
    size = _size;
    tree = new int [size + 5];

    for (int i = 0; i < size + 5; i++) {
      tree[i] = 0;
    }
  }

  void add (int index, int value) {
    for (int i = index; i <= size; i += i & -i) {
      tree[i] += value;
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  int range (int left, int right) {
    if (left > right) {
      return 0;
    } else {
      return get(right) - get(left - 1);
    }
  }
};

fenwick rsqs [BLOCK];
int arr [MAX_SIZE];

int main () {
  ios::sync_with_stdio(false);

  int length, queryc;
  cin >> length >> queryc;

  llong ans = 0;
  for (int i = 0; i < length; i++) {
    arr[i] = i + 1;
    rsqs[i / BLOCK].add(i + 1, 1);
  }

  for (int i = 0; i < queryc; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    
    if (l > r) {
      swap(l, r);
    }

    if (l / BLOCK == r / BLOCK) {
      for (int j = l; j <= r; j++) {
        if (min(arr[l], arr[r]) < arr[j] &&
            arr[j] < max(arr[l], arr[r])) {
          if (arr[l] < arr[r]) {
            ans += 2;
          } else {
            ans -= 2;
          }
        }
      }
    } else {
      int bl, br;
      for (int j = l; true; j++) {
        if (j % BLOCK == 0) {
          bl = j;
          break;
        }

        if (min(arr[l], arr[r]) < arr[j] &&
            arr[j] < max(arr[l], arr[r])) {
          if (arr[l] < arr[r]) {
            ans += 2;
          } else {
            ans -= 2;
          }
        }
      }

      for (int j = r; true; j--) {
        if (min(arr[l], arr[r]) < arr[j] &&
            arr[j] < max(arr[l], arr[r])) {
          if (arr[l] < arr[r]) {
            ans += 2;
          } else {
            ans -= 2;
          }
        }

        if (j % BLOCK == 0) {
          br = j;
          break;
        }
      }

      for (int j = bl; j < br; j += BLOCK) {
        if (arr[l] < arr[r]) {
          ans += 2 * rsqs[j / BLOCK].range(arr[l] + 1, arr[r] - 1);
        } else {
          ans -= 2 * rsqs[j / BLOCK].range(arr[r] + 1, arr[l] - 1);
        }
      }
    }

    if (arr[l] < arr[r]) {
      ans++;
    } else if (arr[l] > arr[r]) {
      ans--;
    }

    rsqs[l / BLOCK].add(arr[l], -1);
    rsqs[l / BLOCK].add(arr[r], 1);
    rsqs[r / BLOCK].add(arr[r], -1);
    rsqs[r / BLOCK].add(arr[l], 1);
    swap(arr[l], arr[r]);

    cout << ans << '\n';
  }
}