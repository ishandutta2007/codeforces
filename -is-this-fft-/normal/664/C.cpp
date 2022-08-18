#include <iostream>
#include <string>

typedef long long llong;

using namespace std;

llong stolll (string s) {
  llong ans = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    ans *= 10;
    ans += s[i] - '0';
  }
  return ans;
}

llong begins [10] = {1989, 1999, 2099, 3099, 13099,
                     113099, 1113099, 11113099,
                     111113099, 1111113099LL};
llong mods [10] = {10, 100, 1000, 10000, 100000,
                   1000000, 10000000, 100000000,
                   1000000000, 10000000000LL};

int main () {
  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    string query;
    cin >> query;
    query = query.substr(4);
    
    llong lquery = stolll(query);
   
    llong bgn = begins[(int) query.size() - 1];
    llong mod = mods[(int) query.size() - 1];
    cout << bgn + (mod + lquery - bgn % mod) % mod << endl;
  }
}