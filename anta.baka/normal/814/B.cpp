/*















*/

#include <bits/stdc++.h>

using namespace std;

int n;

int dif(int a[], int b[]) {
  int res = 0;
  for(int i = 0; i < n; i++) res += (a[i] != b[i]);
  return res;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  vector<int> t;
  for(int i = 0; i < n; i++)
    if(a[i] != b[i]) t.push_back(i);
  int p[n];
  vector<bool> is(n + 1, false);
  if(t.size() == 1) {
    for(int i = 0; i < n; i++) if(i != t[0]) p[i] = a[i], is[a[i]] = true;
    for(int i = 1; i <= n; i++) if(!is[i]) p[t[0]] = i;
  } else {
    vector<int> w;
    for(int i = 0; i < n; i++) if(i != t[0] && i != t[1]) p[i] = a[i], is[a[i]] = true;
    for(int i = 1; i <= n; i++) if(!is[i]) w.push_back(i);
    p[t[0]] = w[0];
    p[t[1]] = w[1];
    if(dif(p, a) != 1 || dif(p, b) != 1) swap(p[t[0]], p[t[1]]);
  }
  for(int i = 0; i < n; i++) cout << p[i] << ' ';
}