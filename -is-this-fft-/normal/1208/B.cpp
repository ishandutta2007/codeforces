#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 2005;

int arr [MAX_N];
int cnt [MAX_N];
int problemc;

void add (int x) {
  cnt[x]++;
  if (cnt[x] == 2) {
    problemc++;
  }
}

void del (int x) {
  cnt[x]--;
  if (cnt[x] == 1) {
    problemc--;
  }
}

int main () {
  int length;
  cin >> length;

  map<int, int> compr;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];

    compr[arr[i]] = 0;
  }

  int cur = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (int i = 0; i < length; i++) {
    arr[i] = compr[arr[i]];
  }

  for (int i = 0; i < length; i++) {
    add(arr[i]);
  }

  if (problemc == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = MAX_N;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < MAX_N; j++) {
      cnt[j] = 0;
    }
    problemc = 0;
    
    for (int j = 0; j < length; j++) {
      add(arr[j]);
    }
    
    for (int j = i; j < length; j++) {
      del(arr[j]);
      if (problemc == 0) {
        ans = min(ans, j - i + 1);
      }
    }
  }
  
  cout << ans << endl;
}