#include <iostream>
#include <set>
#include <string>

using namespace std;

int main () {
  int polandc, enemyc;
  cin >> polandc >> enemyc;

  set<string> poland;
  for (int i = 0; i < polandc; i++) {
    string v;
    cin >> v;
    poland.insert(v);
  }

  int sharedc = 0;
  for (int i = 0; i < enemyc; i++) {
    string v;
    cin >> v;
    if (poland.find(v) != poland.end()) {
      sharedc++;
    }
  }

  polandc -= sharedc;
  polandc += (sharedc + 1) / 2;
  
  enemyc -= sharedc;
  enemyc += sharedc / 2;

  if (polandc > enemyc) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}