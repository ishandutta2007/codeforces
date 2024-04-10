#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

int n, m;
int a[M];
bool used[M];
bool ex[M];
vector<int> st;

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

void kill() {
  int dump = find(a, a + n, 0) - a;
  if (dump == n)
    dump = find(a, a + n, m) - a;
  if (dump == n) {
    cout << "NO\n";
    return;
  }

  st.push_back(1);
  used[1] = true;

  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      a[i] = st.back();
      continue;
    }

    if (used[a[i]] && ex[a[i]]) {
      cout << "NO\n";
      return;
    }

    while (st.back() > a[i]) {
      ex[st.back()] = true;
      st.pop_back();
    }

    if (st.back() != a[i]) {
      st.push_back(a[i]);
      used[a[i]] = true;
    }
  }

  int mx = -1;
  for (int i = 1; i <= m; ++i)
    if (!used[i])
      mx = i;
  if (mx != -1 && a[dump] < mx)
    a[dump] = mx;

  cout << "YES\n";
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << "\n";
  
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}