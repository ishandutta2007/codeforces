#include <iostream>

#define int long long

const int MAXN = 500005;

int left[MAXN];
int a[MAXN];
int right[MAXN];
int vall[MAXN], valr[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for(int i = 0; i < n; i++) {
    left[i] = i-1;
    while(left[i] != -1 && a[left[i]] > a[i])
      left[i] = left[left[i]];
    vall[i] = left[i] == -1 ? 0 : vall[left[i]];
    vall[i] += (i-left[i])*a[i];
  }

  for(int i = n-1; i >= 0; i--) {
    right[i] = i+1;
    while(right[i] != n && a[right[i]] > a[i])
      right[i] = right[right[i]];
    valr[i] = right[i] == n ? 0 : valr[right[i]];
    valr[i] += (right[i]-i)*a[i];
  }

  int ans = -1;
  int cur = -1;
  for(int i = 0; i+1 < n; i++) {
    if(vall[i] + valr[i+1] > ans) {
      ans = vall[i] + valr[i+1];
      cur = i;
    }
  }

  int out[n];
  int val = a[cur];
  for(int i = cur; i >= 0; i--) {
    val = std::min(val, a[i]);
    out[i] = val;
  }

  val = a[cur+1];
  for(int i = cur+1; i < n; i++) {
    val = std::min(val, a[i]);
    out[i] = val;
  }

  for(int i = 0; i < n; i++)
    std::cout << out[i] << " ";
  std::cout << std::endl;

  return 0;
}