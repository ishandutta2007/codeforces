#include <iostream>

const int MAX_QUERY = 100005;
const int MAX_LEN = 1LL << 20;
const char newl = '\n';

typedef long long llong;

using namespace std;

llong convert (llong query) {
  llong ans = 0;
  
  for (llong mult = 1; query > 0; mult *= 2) {
    ans += (query % 2) * mult;
    query /= 10;
  }

  return ans;
}

llong cnt [MAX_LEN];

int main () {
  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    char query;
    llong val;
    
    cin >> query >> val;
    
    if (query == '+') {
      cnt[convert(val)]++;
    } else if (query == '-') {
      cnt[convert(val)]--;
    } else {
      cout << cnt[convert(val)] << newl;
    }
  }
}