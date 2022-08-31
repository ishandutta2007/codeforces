#include <iostream>

using namespace std;

const int MAX_LEN = 100005;
const int MAX_PIX = 300;

int arr [MAX_LEN];
int go_to [MAX_PIX];

int main () {
  for (int i = 0; i < MAX_PIX; i++) {
    go_to[i] = -1;
  }
  
  int length, width;
  cin >> length >> width;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];

    if (go_to[arr[i]] == -1) {
      int gotoi;
      for (int j = arr[i]; j >= 0 && j >= arr[i] - width + 1 &&
             (go_to[j] == -1 || go_to[j] >= arr[i] - width + 1); j--) {
        gotoi = j;
      }

      for (int j = gotoi; j <= arr[i]; j++) {
        go_to[j] = gotoi;
      }
    }

    arr[i] = go_to[arr[i]];
  }

  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}