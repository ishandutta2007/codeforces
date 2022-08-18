#include <iostream>
#define MAX_V 100005

using namespace std;

int datap [MAX_V];

int main () {
  int datac;
  cin >> datac;
  for (int i = 0; i < datac; i++) {
    cin >> datap[i];
  }

  int longest = 1;
  int seql = 1, sequ = 1;
  for (int i = 1; i < datac; i++) {
    if (datap[i-1] < datap[i]) {
      seql = sequ;
      sequ = 0;
    } else if (datap[i-1] > datap[i]) {
      sequ = seql;
      seql = 0;
    }
    sequ++;
    seql++;
    if (longest < max(seql, sequ)) longest = max(seql, sequ);
  }

  cout << longest << endl;
}