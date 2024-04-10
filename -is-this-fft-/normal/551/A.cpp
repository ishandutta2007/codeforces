#include <iostream>
#include <algorithm>

const int MAX_LEN = 2005;

using namespace std;

struct elem {
  int pos, val;
};

bool operator> (elem a, elem b) {
  return a.val > b.val;
}

elem students [MAX_LEN];
int ans [MAX_LEN];

int main () {
  int studentc;
  cin >> studentc;

  for (int i = 0; i < studentc; i++) {
    cin >> students[i].val;
    students[i].pos = i;
  }

  sort(students, students + studentc, greater<elem>());

  int place = 1;
  for (int i = 0; i < studentc; i++) {
    if (i == 0 || students[i - 1].val != students[i].val) {
      place = i + 1;
    }
    ans[students[i].pos] = place;
  }

  for (int i = 0; i < studentc; i++) {
    cout << ans[i] << (i == studentc - 1 ? '\n' : ' ');
  }
}