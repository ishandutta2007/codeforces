#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int N = 300005;

int n, swp, at;
ll x_1, x_2;
pii c[N];
vector <int> v_1, v_2;

void print() {
  if (swp) swap(v_1, v_2);
  puts("Yes");
  int k_1 = v_1.size(), k_2 = v_2.size();
  cout << k_1 << " " << k_2 << '\n';
  for (int i = 0; i < k_1; ++i) {
    printf("%d ", v_1[i]);
  }
  puts("");
  for (int i = 0; i < k_2; ++i) {
    printf("%d ", v_2[i]);
  }
  puts("");
}

int main() {
  cin >> n >> x_1 >> x_2;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &c[i].first);
    c[i].second = i;
  }
  sort(c + 1, c + n + 1);
  
  at = -1;
  for (int i = n; i >= 2; --i) {
    if ((n - i + 1LL) * c[i].first >= x_2) {
      at = i;
      for (int j = i; j <= n; ++j) {
        v_2.push_back(c[j].second);
      }
      break;
    }
  }
  for (int i = at - 1; i >= 1; --i) {
    if ((at - i) * 1LL * c[i].first >= x_1) {
      for (int j = i; j < at; ++j) {
        v_1.push_back(c[j].second);
      }
      print();
      return 0;
    }
  }
    
  v_1.clear(), v_2.clear();
  swap(x_1, x_2), swp = 1;

  at = -1;
  for (int i = n; i >= 2; --i) {
    if ((n - i + 1LL) * c[i].first >= x_2) {
      at = i;
      for (int j = i; j <= n; ++j) {
        v_2.push_back(c[j].second);
      }
      break;
    }
  }
  for (int i = at - 1; i >= 1; --i) {
    if ((at - i) * 1LL * c[i].first >= x_1) {
      for (int j = i; j < at; ++j) {
        v_1.push_back(c[j].second);
      }
      print();
      return 0;
    }
  }

  puts("No");
  return 0;
}