#include <bits/stdc++.h>

using namespace std;

const int M = 100100;
#define long long long

long n;
pair<long, long> input[M];
long a[M];
long b[M];
int last = 1;
long lb = 0, lv = 0;
long rb = 0;
long A;
long cf, cm, m;

void read() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 0; i < n; ++i) {
    cin >> input[i].first;
    input[i].second = i;
  }
  sort(input, input + n);
  for (int i = 0; i < n; ++i)
    a[i] = input[i].first;
}


void add() {
  if (last == n + 1)
    return;
  long d = a[last] - a[last - 1];
  if (d * last > m)
    return;
  m -= d * last;
  ++last;
}

void rem() {
  if (last == 1)
    return;
  long d = (a[last - 1] - a[last - 2]);
  m += d * (last - 1);
  --last;
}

long kill() {
  a[n] = A;
  for (int i = 0; i - 2 < n; ++i)
    add();


  if (last == n + 1) {
    lb = n;
    lv = A;
    rb = 0;
    return n * cf + A * cm;
  }

  long ans = 0;
  for (int i = n; i > 0; --i) {
    while (last > i)
      rem();
    while (m < A - a[i] && last >= 2)
      rem();
    if (m < A - a[i])
      return ans;

    m -= A - a[i];
    long nans = cf * (n - i) + cm * (a[last - 1] + (m / last));
    if (nans >= ans) {
      ans = nans;
      lb = last;
      lv = a[last - 1] + (m / last);
      rb = (n - i);
    }
  }

  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);

  read();
  cout << kill() << endl;
  for (int i = 0; i < n; ++i)
    b[input[i].second] = a[i];
  for (int i = 0; i < lb; ++i)
    b[input[i].second] = max(a[i], lv);
  for (int i = 0; i < rb; ++i)
    b[input[n - i - 1].second] = A;
  for (int i = 0; i < n; ++i)
    cout << b[i] << " ";
  cout << endl;
}