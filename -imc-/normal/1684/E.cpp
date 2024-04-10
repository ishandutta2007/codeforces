#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

struct Item {
  int cnt;
  int value;

  bool operator<(const Item& rhs) const {
    return make_pair(cnt, value) > make_pair(rhs.cnt, rhs.value);
  }
};

int get_diff(vector<int> a) {
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  return a.size();
}

int get_mex(vector<int> a) {
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != i) return i;
  }
  return a.size();
}

void solve(bool read) {
  int n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = rand() % 10 + 1;
    k = rand() % 10 + 1;

    //n = 2e5;
    //k = 2e5;
  }
  vector<int> a(n);
  map<int, int> cntm;
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % (n + 2);
      static int counter = 0;
      x = ++counter;
    }
    cntm[x]++;
  }
  sort(all(a));

  vector<Item> items;
  for (auto it : cntm) {
    items.push_back(Item{it.second, it.first});
  }
  sort(all(items));

  map<int, int> item_index_by_value;
  for (int i = 0; i < items.size(); ++i) {
    item_index_by_value[items[i].value] = i;
  }

  int num_missing = 0;

  int squash_sum = 0;
  int squash_pos = items.size();
  int cnt_squash_zero = 0;

  int min_can = 1e9;

  for (int mex = 0; mex <= n; ++mex) {
    // purge mex-1
    if (mex - 1 >= 0 && item_index_by_value.count(mex - 1)) {
      int index = item_index_by_value[mex - 1];
      Item& erased = items[index];
      //items.erase(items.begin() + index);
      //for (int i = index; i < items.size(); ++i) {
      //  item_index_by_value[items[i].value] = i;
      //}

      if (index < squash_pos) {
        //--squash_pos;
        ++cnt_squash_zero;
      } else {
        squash_sum -= erased.cnt;
        assert(squash_sum >= 0);
      }

      erased.cnt = 0;
    } else if (mex - 1 >= 0) {
      ++num_missing;
    }

    while (squash_pos > 0 && squash_sum + items[squash_pos - 1].cnt <= k) {
      if (items[squash_pos - 1].cnt == 0) {
        --cnt_squash_zero;
      }

      squash_sum += items[squash_pos - 1].cnt;
      --squash_pos;
    }

    //int squashed = squash_sum;
    if (k < num_missing) {
      //cout << "mex: " << mex << " squashed: " << squashed << " missing: " << num_missing << "\n";
      continue;
    }

    int diff = 0;
    diff += mex;
    diff += squash_pos - cnt_squash_zero;
    diff = max(diff, 1);

    int can = diff - mex;

    /*cout << "with mex: " << mex << " diff: " << diff << " can: " << can << " items: ";
    for (auto it : items) cout << it.cnt << ":" << it.value << " ";
    cout << " squash_pos: " << squash_pos << "\n";*/
    min_can = min(min_can, can);
  }

  cout << min_can << "\n";

  if (false) {
    cout << "TEST:\n";
    cout << n << " " << k << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    int min_exp = 1e9;

    for (int mex = 0; mex <= n; ++mex) {
      vector<int> nums = a;

      auto most_freq_ge = [&]() {
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] >= mex) {
            ++cnt[nums[i]];
          }
        }
        int min_cnt_best = -1;
        int min_cnt = 1e9;
        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] >= mex) {
            if (cnt[nums[i]] < min_cnt) {
              min_cnt_best = i;
              min_cnt = cnt[nums[i]];
            }
          }
        }
        if (min_cnt_best == -1) {
          for (int i = 0; i < nums.size(); ++i) {
            if (count(all(nums), nums[i]) > 1) {
              return i;
            }
          }
        }

        return min_cnt_best;
      };

      int rem_k = k;
      bool fail = false;
      for (int i = 0; i < mex; ++i) {
        if (find(all(nums), i) == nums.end()) {
          int index = most_freq_ge();
          if (index == -1 || rem_k == 0) {
            // all nums < mex
            fail = true;
            break;
          }

          --rem_k;
          nums.erase(nums.begin() + index);
          nums.push_back(i);
        }
      }
      while (rem_k > 0) {
        int index = most_freq_ge();
        if (index == -1) break;
        nums.erase(nums.begin() + index);
        nums.push_back(0);
        --rem_k;
      }

      sort(all(nums));

      int MEX = get_mex(nums);
      int DIFF = get_diff(nums);
      int can = DIFF - MEX;
      min_exp = min(min_exp, can);

      cout << "can mex: " << mex << " MEX: " << MEX << " DIFF: " << DIFF << " can: " << can << " array: "; for (auto it : nums) cout << it << " "; cout << "\n";
    }

    cout << "expected: " << min_exp << endl;
    assert(min_exp == min_can);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  //while (true) solve(false);

  return 0;
}