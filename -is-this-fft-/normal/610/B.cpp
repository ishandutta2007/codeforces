#include <iostream>

const int MAX_N = 200005;
const int INF = 1000000001;

using namespace std;

long long numbers [MAX_N];

int main () {
  long long length, smallest = INF;

  cin >> length;
  for (int i = 0; i < length; i++) {
    cin >> numbers[i];
    if (numbers[i] < smallest) {
      smallest = numbers[i];
    }
  }

  long long curlen = 0, bestlen = 0;
  for (int i = 0; i < 2 * length; i++) {
    if (numbers[i % length] == smallest) {
      curlen = 0;
    } else {
      curlen++;
      if (curlen > bestlen) {
	bestlen = curlen;
      }
    }
  }

  if (bestlen > length) {
    bestlen = length;
  }

  cout << length * smallest + bestlen << endl;
}