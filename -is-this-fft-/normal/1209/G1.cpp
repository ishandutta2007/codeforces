#include <iostream>
#include <vector>

using namespace std;

const int MAX_D = 200005;

int arr [MAX_D];
int firstOcc [MAX_D];
int lastOcc [MAX_D];
int startc [MAX_D]; 
int finishc [MAX_D];
int freq [MAX_D];

int main () {
  ios::sync_with_stdio(false);
  
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < MAX_D; i++) {
    firstOcc[i] = MAX_D;
    lastOcc[i] = -45;
  }

  for (int i = 0; i < length; i++) {
    firstOcc[arr[i]] = min(i, firstOcc[arr[i]]);
    lastOcc[arr[i]] = max(i, lastOcc[arr[i]]);
  }

  for (int i = 0; i < MAX_D; i++) {
    if (firstOcc[arr[i]] <= lastOcc[arr[i]]) {
      startc[firstOcc[arr[i]]]++;
      finishc[lastOcc[arr[i]]]++;
    }
  }

  vector<pair<int, int>> segs;
  int curStart = 0;
  int curSegs = 0;
  for (int i = 0; i < length; i++) {
    curSegs += startc[i];
    curSegs -= finishc[i];
    if (curSegs == 0) {
      segs.push_back(make_pair(curStart, i));
      curStart = i + 1;
    }
  }

  int ans = length;
  for (pair<int, int> pr : segs) {
    for (int i = pr.first; i <= pr.second; i++) {
      freq[arr[i]]++;
    }

    int mostFreq = 0;
    for (int i = pr.first; i <= pr.second; i++) {
      mostFreq = max(mostFreq, freq[arr[i]]);
    }

    ans -= mostFreq;
  }

  cout << ans << endl;
}