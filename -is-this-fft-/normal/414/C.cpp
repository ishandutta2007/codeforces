#include <iostream>
#include <map>
#include <vector>
#include <cassert>

typedef long long llong;

const int MAX_LEN = 1 << 21;
const int MAX_BIT = 21;

using namespace std;

llong arr [MAX_LEN][2], invc [MAX_BIT][2], flipped [MAX_BIT];

void merge_sort (llong left, llong right, llong depth, llong mode) {
  if (right - left > 1) {
    merge_sort(left, (left + right) / 2, depth - 1, mode);
    merge_sort((left + right) / 2, right, depth - 1, mode);
  } else {
    assert(depth == 0);
    return;
  }

  vector<llong> temp;
  llong aptr = left, bptr = (left + right) / 2;
  while (aptr < (left + right) / 2 && bptr < right) {
    llong ltop = arr[aptr][mode], rtop = arr[bptr][mode];

    if (ltop < rtop) {
      temp.push_back(ltop);
      aptr++;

      if (mode == 1) {
        invc[depth][mode] += right - bptr;
      }
    } else if (ltop == rtop) {
      if (mode == 0) {
        temp.push_back(ltop);
        aptr++;
      } else {
        temp.push_back(rtop);
        bptr++;
      }
    } else {
      temp.push_back(rtop);
      bptr++;

      if (mode == 0) {
        invc[depth][mode] += (left + right) / 2 - aptr;
      }
    }
  }

  while (aptr < (left + right) / 2) {
    temp.push_back(arr[aptr][mode]);
    aptr++;
  }

  while (bptr < right) {
    temp.push_back(arr[bptr][mode]);
    bptr++;
  }

  for (llong i = 0; i < (llong) temp.size(); i++) {
    arr[i + left][mode] = temp[i];
  }
}

int main () {
  ios::sync_with_stdio(false);

  llong length;
  cin >> length;

  for (llong i = 0; i < 1 << length; i++) {
    cin >> arr[i][0];
    arr[i][1] = arr[i][0];
  }

  merge_sort(0, 1 << length, length, 0);
  merge_sort(0, 1 << length, length, 1);

  /*
  for (llong i = length; i > 1; i--) {
    invc[i][0] -= invc[i - 1][0];
    invc[i][1] -= invc[i - 1][1];
  }
  */

  llong cur_ans = 0;
  for (llong i = 1; i <= length; i++) {
    cur_ans += invc[i][0];
  }

  llong queryc;
  cin >> queryc;
  for (llong i = 0; i < queryc; i++) {
    llong query;
    cin >> query;
    
    for (llong j = query; j > 0; j--) {
      flipped[j] = !flipped[j];
      cur_ans -= invc[j][!flipped[j]];
      cur_ans += invc[j][flipped[j]];
    }

    cout << cur_ans << '\n';
  }
}