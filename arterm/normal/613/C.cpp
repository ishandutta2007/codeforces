#include <bits/stdc++.h>

using namespace std;

bool isGood(vector<int> a) {
  int odd = 0;
  for (int x : a) 
    if (x & 1)
      ++odd;
  return odd <= 1;
}

int gcd(int x, int y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

vector<int> read() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  return a;
}

string makePal(vector<int> a) {
  string half = "";
  string mid = "";
  char c = 'a';
  for (int x : a) {
    if (x & 1)
      mid = mid + string(1, c);
    
    half += string(x / 2, c);

    c = c + 1;
  }
  
  string rev = half;
  reverse(rev.begin(), rev.end());
  return half + mid + rev;
}

int main() {
  ios_base::sync_with_stdio(false);
  auto a = read();
  int d = 0;
  for (int x : a)
    d = gcd(d, x);

  auto b = a;
  int res = d;
  for (int &x : b)
    x /= d;

  if (!isGood(b) && d % 2 == 0) {
    d /= 2;
    for (int &x : b)
      x *= 2;
  }

  string ans = makePal(b);
  string t = "";
  for (int i = 0; i < d; ++i)
    t = t + ans;

  cout << (isGood(b) ? res : 0) << endl;
  cout << t << endl;
}