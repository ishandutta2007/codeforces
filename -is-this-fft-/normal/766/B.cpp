#include <iostream>
#include <algorithm>

const int MAX_LEN = 100005;

using namespace std;

int lengths [MAX_LEN];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> lengths[i];
  }

  sort(lengths, lengths + length);

  for (int i = 1; i < length - 1; i++) {
    if (lengths[i - 1] + lengths[i] > lengths[i + 1] &&
        lengths[i] + lengths[i + 1] > lengths[i - 1] &&
        lengths[i - 1] + lengths[i + 1] > lengths[i]) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}