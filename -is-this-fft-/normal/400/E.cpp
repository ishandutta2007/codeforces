#include <iostream>
#include <set>

typedef long long llong;

const int MAX_BIT = 18;
const int MAX_LEN = 100005;

using namespace std;

struct interval {
  int left, right;

  interval () {
  }

  interval (int _left) {
    left = _left;
    right = _left + 1;
  }

  interval (int _left, int _right) {
    left = _left;
    right = _right;
  }

  llong length () {
    return right - left;
  }

  llong triangle () {
    return length() * (length() + 1) / 2;
  }

  void print () {
    cout << "[" << left << "; " << right << ") ";
  }
};

bool operator< (interval p, interval q) {
  if (p.left == q.left) {
    return p.right < q.right;
  } else {
    return p.left < q.left;
  }
}

set<interval> blocks [MAX_BIT];
int arr [MAX_LEN];

int main () {
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];

    if (i == 0) {
      for (int j = 0; j < MAX_BIT; j++) {
        if (arr[i] & 1 << j) {
          blocks[j].insert(interval(0));
        }
      }
    } else {
      for (int j = 0; j < MAX_BIT; j++) {
        if (arr[i] & 1 << j) {
          if (arr[i - 1] & 1 << j) {
            interval last = *blocks[j].rbegin();
            blocks[j].erase(last);
            last.right++;
            blocks[j].insert(last);
          } else {
            blocks[j].insert(interval(i));
          }
        }
      }
    }
  }

  llong ans = 0;
  for (int j = 0; j < MAX_BIT; j++) {
    for (auto i = blocks[j].begin(); i != blocks[j].end(); i++) {
      interval cur = *i;
      ans += cur.triangle() * (1LL << j);
    }
  }

  for (int i = 0; i < queryc; i++) {
    int pos, val;
    cin >> pos >> val;
    pos--;
    
    int change = arr[pos] ^ val;
    for (int j = 0; j < MAX_BIT; j++) {
      if (change & 1 << j) {
        if (val & 1 << j) { /* 0 -> 1 */
          if (blocks[j].size() == 0) {
            ans += 1LL << j;
            blocks[j].insert(interval(pos));
          } else {
            auto lb = blocks[j].lower_bound(interval(pos));
            interval rir = *lb;
            
            if (lb == blocks[j].begin()) {
              if (rir.left == pos + 1) {
                blocks[j].erase(rir);
                ans -= rir.triangle() * (1LL << j);
                rir.left--;
                blocks[j].insert(rir);
                ans += rir.triangle() * (1LL << j);
              } else {
                blocks[j].insert(interval(pos));
                ans += 1LL << j;
              }
            } else {
              lb--;
              auto llb = lb;
              lb++;

              interval lir = *llb, rir = *lb;
              
              if (lb == blocks[j].end()) {
                if (lir.right == pos) {
                  blocks[j].erase(lir);
                  ans -= lir.triangle() * (1LL << j);
                  lir.right++;
                  blocks[j].insert(lir);
                  ans += lir.triangle() * (1LL << j);
                } else {
                  blocks[j].insert(interval(pos));
                  ans += 1LL << j;
                }
              } else {
                if (lir.right == pos && rir.left == pos + 1) {
                  blocks[j].erase(lir);
                  ans -= lir.triangle() * (1LL << j);
                  
                  blocks[j].erase(rir);
                  ans -= rir.triangle() * (1LL << j);
                  
                  lir.right = rir.right;
                  blocks[j].insert(lir);
                  ans += lir.triangle() * (1LL << j);
                } else if (lir.right == pos) {
                  blocks[j].erase(lir);
                  ans -= lir.triangle() * (1LL << j);
                  lir.right++;
                  blocks[j].insert(lir);
                  ans += lir.triangle() * (1LL << j);
                } else if (rir.left == pos + 1) {
                  blocks[j].erase(rir);
                  ans -= rir.triangle() * (1LL << j);
                  rir.left--;
                  blocks[j].insert(rir);
                  ans += rir.triangle() * (1LL << j);
                } else {
                  blocks[j].insert(interval(pos));
                  ans += 1LL << j;
                }
              }            
            }
          }
        } else { /* 1 -> 0 */
          auto ub = blocks[j].upper_bound(interval(pos, MAX_LEN));
          ub--;

          interval cur = *ub;
          
          if (pos == cur.left) {
            blocks[j].erase(cur);
            ans -= cur.triangle() * (1LL << j);
            
            cur.left++;
            blocks[j].insert(cur);
            ans += cur.triangle() * (1LL << j);
          } else if (pos == cur.right - 1) {
            blocks[j].erase(cur);
            ans -= cur.triangle() * (1LL << j);
            
            cur.right--;
            blocks[j].insert(cur);
            ans += cur.triangle() * (1LL << j);
          } else {
            blocks[j].erase(cur);
            ans -= cur.triangle() * (1LL << j);

            interval lir (cur.left, pos), rir (pos + 1, cur.right);
            blocks[j].insert(lir);
            ans += lir.triangle() * (1LL << j);
            
            blocks[j].insert(rir);
            ans += rir.triangle() * (1LL << j);
          }
        }
      }
    }
    
    cout << ans << '\n';
    arr[pos] = val;

    /*
    for (int j = 0; j < 3; j++) {
      for (auto i = blocks[j].begin(); i != blocks[j].end(); i++) {
        ((interval) *i).print();
      }
      cout << endl;
    }
    */
  }
}