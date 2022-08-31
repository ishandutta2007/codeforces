#include <iostream>

const int MAX_PRIM = 1000005;

using namespace std;

bool composite [MAX_PRIM];

int main () {
  for (int i = 2; i < MAX_PRIM; i++) {
    if (!composite[i]) {
      for (int j = 2*i; j < MAX_PRIM; j+=i) {
        composite[j] = true;
      }
    }
  }

  int num;
  cin >> num;

  if (num == 2) {
    cout << "1\n1 1\n";
  } else if (num == 1) {
    cout << "1\n1\n";
  }else{
    cout << 2 << endl;

    for (int i = 2; i <= num + 1; i++) {
      if (composite[i]) {
        cout << 1 << " ";
      } else {
        cout << 2 << " ";
      }
    }
    cout << endl;
  }
}