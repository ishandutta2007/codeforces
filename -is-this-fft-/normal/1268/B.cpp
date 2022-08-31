#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  ll wc = 0, bc = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    wc += x / 2;
    bc += (x + 1) / 2;
    swap(wc, bc);
  }

  cout << min(wc, bc) << endl;
}