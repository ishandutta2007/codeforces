#include <iostream>
#include <map>
#include <set>

const int MAX_LEN = 100005;
const char newl = '\n';

using namespace std;

int arr [MAX_LEN];

int main () {
  int arrlen, sublen;
  cin >> arrlen >> sublen;

  map<int, int> cnt;
  for (int i = 0; i < arrlen; i++) {
    cin >> arr[i];
    cnt[arr[i]] = 0;
  }


  set<int, greater<int> > ans;
  for (int i = 0; i < sublen; i++) {
    cnt[arr[i]]++;
    if (cnt[arr[i]] == 1) {
      ans.insert(arr[i]);
    } else if (cnt[arr[i]] == 2) {
      ans.erase(arr[i]);
    }
  }
  if (ans.size() == 0) {
    cout << "Nothing" << newl;
  } else {
    cout << *ans.begin() << newl;
  }

  for (int i = sublen; i < arrlen; i++) {
    cnt[arr[i]]++;
    if (cnt[arr[i]] == 1) {
      ans.insert(arr[i]);
    } else if (cnt[arr[i]] == 2) {
      ans.erase(arr[i]);
    }

    cnt[arr[i - sublen]]--;
    if (cnt[arr[i - sublen]] == 1) {
      ans.insert(arr[i - sublen]);
    } else if (cnt[arr[i - sublen]] == 0) {
      ans.erase(arr[i - sublen]);
    }

    if (ans.size() == 0) {
      cout << "Nothing" << newl;
    } else {
      cout << *ans.begin() << newl;
    }
  }
}