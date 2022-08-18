#include <iostream>
#include <string>

using namespace std;

const int MAX_K = 22;

string a [MAX_K];
string b [MAX_K];

int main () {
  ios::sync_with_stdio(false);
  
  int ac, bc;
  cin >> ac >> bc;

  for (int i = 0; i < ac; i++) {
    cin >> a[i];
  }

  for (int j = 0; j < bc; j++) {
    cin >> b[j];
  }

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int x;
    cin >> x;
    x--;

    cout << a[x%ac] << b[x%bc] << '\n';
  }
}