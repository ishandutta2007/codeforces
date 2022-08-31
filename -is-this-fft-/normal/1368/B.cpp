#include <iostream>

using namespace std;

typedef long long ll;

char let [10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
ll mul [10];

int main () {
  ll k;
  cin >> k;

  ll ways = 1;
  for (int i = 0; i < 10; i++) mul[i] = 1;

  if (k == 1) {
    cout << "codeforces" << endl;
    return 0;
  }
  
  for (int i = 0; true; i++) {
    ways /= mul[i % 10];
    mul[i % 10]++;
    ways *= mul[i % 10];
    if (ways >= k) break;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < mul[i]; j++) {
      cout << let[i];
    }
  }
  cout << endl;
}