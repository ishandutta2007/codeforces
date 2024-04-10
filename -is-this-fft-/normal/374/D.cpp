#include <iostream>
#include <vector>

const int MAX_QUERY = 1000005;
const int INF = 1023456789;

using namespace std;

int chosen [MAX_QUERY], leftlink [MAX_QUERY], dp [MAX_QUERY];

int main () {
  ios::sync_with_stdio(false);

  int queryc, chosenc;
  cin >> queryc >> chosenc;

  for (int i = 0; i < chosenc; i++) {
    int index;
    cin >> index;
    index--;

    chosen[index] = 1;
  }

  leftlink[0] = 0;
  for (int i = 1; i < MAX_QUERY; i++) {
    leftlink[i] = leftlink[i - 1] + chosen[i - 1];
  }

  for (int i = 0; i < MAX_QUERY; i++) {
    if (chosen[i]) {
      break;
    }
    dp[i] = INF;
  }

  for (int i = 1; i < MAX_QUERY; i++) {
    if (chosen[i]) {
      dp[i] = 0;
    } else {
      dp[i] = dp[i - leftlink[i]] + 1;
    }
  }

  int length = 0, slamc = 0;
  vector<pair<int, int> > elements;
  for (int i = 0; i < queryc; i++) {
    int query;
    cin >> query;

    if (query == -1) {
      slamc++;
      length -= leftlink[length];
    } else {
      elements.push_back(make_pair(query, slamc + dp[length]));
      length++;
    }
  }

  if (length == 0) {
    cout << "Poor stack!";
  }

  for (int i = 0; i < (int) elements.size(); i++) {
    if (elements[i].second >= slamc) {
      cout << elements[i].first;
    }
  }
  cout << endl;
}