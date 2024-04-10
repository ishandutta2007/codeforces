#include <iostream>

using namespace std;

int gcd (int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int magic [] =
  {-1,
   -1, 
   1, 
   1, 
   5, 
   1, 
   21, 
   1, 
   85, 
   73, 
   341, 
   89, 
   1365, 
   1, 
   5461, 
   4681, 
   21845, 
   1, 
   87381, 
   1, 
   349525, 
   299593, 
   1398101, 
   178481, 
   5592405, 
   1082401};

int len (int x) {
  int ans = 0;
  while (x != 0) {
    x >>= 1;
    ans++;
  }
  return ans;
}

bool all_ones (int x) {
  while (x % 2 == 1) {
    x >>= 1;
  }
  return (x == 0);
}

int main () {
  int queryc;
  cin >> queryc;  

  for (int i = 0; i < queryc; i++) {
    int num;
    cin >> num;

    if (all_ones(num)) {
      cout << magic[len(num)] << '\n';
    } else {
      cout << ((1 << (len(num))) - 1) << '\n';
    }
  }
}