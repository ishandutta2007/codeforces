#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1000100;

bitset<M> a;
int n, K;
vector<int> c;
int p[M];
bool u[M];
int cnt[M];

void read() {
  cin >> n >> K;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
}

void kill() {
  for (int i = 0; i < n; ++i)
    if (!u[i]) {
      int len = 0;
      int x = i;
      while (!u[x]) {
        ++len;
        u[x] = true;
        x = p[x];
      }
      c.push_back(len);
      cnt[len]++;
      //cerr << len << "!\n";
    }
}

int mn() {
  a[0] = 1;

  for (int x = 1; x <= n; ++x)
    if (cnt[x]) {
      int pw = 1;
      int rest = cnt[x];
      while (rest >= pw) {
        a |= (a << (pw * x));
        rest -= pw;
        pw *= 2;
      }
      a |= (a << (rest * x));

      //for (int i = 0; i < n; ++i)
        //cerr << a[i];
      //cerr << "!\n";
    }

  int k = K;
  //cerr << "k = " << k << endl;

  if (a[k])
    return k;
  else
    return k + 1;
}

int mx() {
  int t = 0;
  int one = 0;
  for (int len : c) {
    t += len / 2;
    one += len % 2;
  }

  int ans = 0;
  int k = K;
  ans += 2 * min(t, k);
  k -= min(t, k);
  ans += min(one, k);
  
  return ans;
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
  cout << mn() << " " << mx() << endl;
}