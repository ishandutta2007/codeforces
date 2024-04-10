#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

int n, cnt0[50], cnt[50];
vector <ll> v;
map <ll, int> lg;
int seq[50];

int main (int argc, char const *argv[]) {
  for (int i = 0; i < 40; ++i) {
    ll two = 1ll << i;
    lg[two] = i;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    ll x; scanf("%lld", &x);
    if (lg.find(x) != lg.end()) {
      ++cnt0[lg[x]];
    } else {
      v.push_back(x);
    }
  }
  int sol = 0;
  for (int sz = 1; sz <= n; ++sz) {
    // cout << " ------------------------------- \n";
    for (int i = 0; i <= 40; ++i) {
      cnt[i] = cnt0[i];
    }
    memset(seq, 0, sizeof seq);
    int rem = sz;
    for (int i = 40; i >= 0; --i) {
      if (cnt[i]) {
        int mn = 10000000;
        for (int j = i; j >= 0; --j) {
          mn = min(mn, cnt[j]);
        }
        if (mn < 10000000) {
          mn = min(mn, rem);
          rem -= mn;
          for (int j = i; j >= 0; --j) {
            cnt[j] -= mn;
          }
          seq[i] += mn;
          if (rem == 0) break;
        }
      }
    }
    // cout << rem << endl;
    // for (int i = 40; i >= 0; --i) {
    //   if (seq[i]) cout << (1ll << i) << " --> " << seq[i] << endl;
    //   if (cnt[i]) cout << "cnt " << i << " --> " << cnt[i] << endl;
    // }
    if (rem) continue;
    int no = 0;
    for (int i = 40; i >= 0; --i) {
      if (cnt[i]) {
        for (int j = i; j <= 40; ++j) {
          if (seq[j] > cnt[i]) {
            seq[j] -= cnt[i];
            cnt[i] = 0;
          } else {
            cnt[i] -= seq[j];
            seq[j] = 0;
          }
          if (cnt[i] == 0) break;
        }
      }
      if (cnt[i]) {
        no = 1;
        break;
      }
    }
    if (no) continue;
    for (ll xx : v) {
      int done = 0;
      for (int j = 0; j <= 40; ++j) {
        if ((1ll << (j + 1)) >= xx) {
          if (seq[j]) {
            // if (sz == 2) cout << "yo\n" << (1ll << j) << " " << xx << endl;
            seq[j]--;
            done = 1;
            break;
          }
        }
      }
      if (done == 0) {
        no = 1;
        break;
      }
    }
    if (no) continue;
    printf("%d ", sz);
    ++sol;
  }
  if (sol == 0) {
    puts("-1");
  } else {
    puts("");
  }

  // for (int i = 40; i >= 1; --i) {
  //   if (cnt[i]) {
  //     int mn = 10000000;
  //     for (int j = i - 1; j >= 0; --j) {
  //       mn = min(mn, cnt[j]);
  //     }
  //     if (mn < 10000000) {
  //       seq[i] = mn;
  //       for (int j = i; j >= 0; --j) {
  //         cnt[j] -= mn;
  //       }
  //     }
  //   }
  // }
  // for (int j = 40; j >= 1; --j) {
  //   for (int k = 0; k < cnt[j]; ++k) {
  //     v.push_back(1ll << j);
  //   }
  // }
  // int one = cnt[0], tot = 0;
  // for (int i = 40; i >= 0; --i) {
  //   if (seq[i]) {
  //     ++tot;
  //     cout << (1ll << i) << " : " << seq[i] << endl;
  //   }
  // }
  // for (ll x : v) cout << x << " "; cout << endl;
  
  return 0;
}