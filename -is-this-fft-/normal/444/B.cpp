#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 1e5 + 5;
 
typedef long long ll;
 
int n, d;
ll x;
int a [MAX_N], b [MAX_N], pos [MAX_N];
 
ll getNextX () {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
 
void initAB () {
  for (int i = 0; i < n; i = i + 1){
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1){
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i = i + 1){
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1){
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
 
const int BLOCK = 20;
 
int main () {
  ios::sync_with_stdio(false);
 
  cin >> n >> d >> x;
  initAB();
 
  /*
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
 
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  */
  
  if (d < BLOCK) {
    vector<int> nonzeros;
    for (int i = 0; i < n; i++) {
      if (b[i] != 0) {
        nonzeros.push_back(i);
      }
    }
 
    for (int i = 0; i < n; i++) {
      int ans = 0;
      for (int b_idx : nonzeros) {
        int a_idx = i - b_idx;
        if (a_idx >= 0 && a_idx < n) {
          ans = max(ans, a[a_idx]);
        }
      }
      cout << ans << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
      int ans = 0;
      for (int j = n; j >= 1; j--) {
        int a_idx = pos[j];
        int b_idx = i - a_idx;
        if (b_idx >= 0 && b_idx < n && b[b_idx]) {
          ans = j;
          break;
        }
      }
      cout << ans << '\n';
    }
  }
}