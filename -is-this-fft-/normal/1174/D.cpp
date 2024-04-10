#include <iostream>
#include <vector>

using namespace std;

const int MAX_K = 1 << 18;

int seen [MAX_K]; 

int main () {
  ios::sync_with_stdio(false);
  
  int k, x;
  cin >> k >> x;

  vector<int> pref;
  for (int i = 0; i < 1 << k; i++) {
    if (!seen[i ^ x]) {
      seen[i] = 1;
      pref.push_back(i);
    }
  }

  cout << (int) pref.size() - 1 << endl;
  for (int i = 1; i < (int) pref.size(); i++) {
    cout << (pref[i] ^ pref[i - 1]) << " ";
  }
  cout << endl;
}