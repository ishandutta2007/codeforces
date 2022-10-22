#include <iostream>
#include <vector>

using namespace std;

const int MAX_B = 30;

struct Node {
  Node *n0, *n1;
  int v0, v1;

  Node () {
    n0 = nullptr;
    n1 = nullptr;
    v0 = 0;
    v1 = 0;
  }

  Node* go (int bit) {
    if (bit == 0) return n0;
    return n1;
  }

  Node* ensure (int bit) {
    if (bit == 0) {
      if (n0 == nullptr) {
        n0 = new Node();
      }
      return n0;
    } else {
      if (n1 == nullptr) {
        n1 = new Node();
      }
      return n1;
    }
  }

  int& at (int bit) {
    if (bit == 0) return v0;
    return v1;
  }
};

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  Node *trie = new Node();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int dp = 0;
    Node *cur = trie;
    for (int j = MAX_B - 1; j >= 0 && cur != nullptr; j--) {
      Node *oth = cur->go(!((arr[i] ^ i) & 1 << j));
      if (oth != nullptr) {
        dp = max(dp, oth->at(i & 1 << j));
      }
      cur = cur->go((arr[i] ^ i) & 1 << j);
    }
    
    dp++;
    ans = max(ans, dp);

    cur = trie;
    for (int j = MAX_B - 1; j >= 0; j--) {
      cur = cur->ensure((arr[i] ^ i) & 1 << j);
      cur->at(arr[i] & 1 << j) = max(cur->at(arr[i] & 1 << j), dp);
    }
  }
  
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}