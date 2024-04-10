#include <iostream>

using namespace std;

const int maxn = 100005;

int arr [maxn];
int pos [maxn];
char wins [maxn];

int main () {
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  for (int i = length; i >= 1; i--) {
    int cur = pos[i];
    bool ana = true;
    for (int j = 1; cur + i * j <= length || cur - i * j >= 1; j++) {
      if (cur + i * j <= length && arr[cur + i * j] > i && wins[cur + i * j] == 'B') {
        ana = false;
      }

      if (cur - i * j >= 1 && arr[cur - i * j] > i && wins[cur - i * j] == 'B') {
        ana = false;
      }
    }

    if (ana) {
      wins[cur] = 'B';
    } else {
      wins[cur] = 'A';
    }
  }

  for (int i = 1; i <= length; i++) {
    cout << wins[i];
  }
  cout << endl;
}