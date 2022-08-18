#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

typedef long long llong;

const int MAX_P = 3005;

vector<llong> voters [MAX_P];
llong cost_to [MAX_P][MAX_P];
vector<pair<llong, pair<int, int>>> all_voters;
int partyc;

llong cost_with (int everyone_to) {
  int er_cnt = (int) voters[1].size();
  llong ans = 0;

  for (int i = 2; i <= partyc; i++) {
    ans += cost_to[i][everyone_to];
    er_cnt += max(0, (int) voters[i].size() - everyone_to);
  }

  for (int i = 0; i < (int) all_voters.size(); i++) {
    if (er_cnt > everyone_to) {
      break;
    }

    if (all_voters[i].second.second < everyone_to) {
      ans += all_voters[i].first;
      er_cnt++;
    }

    if (er_cnt > everyone_to) {
      break;
    }
  }

  assert(er_cnt > everyone_to);
  return ans;
}

int main () {
  int voterc;
  cin >> voterc >> partyc;

  for (int i = 0; i < voterc; i++) {
    int party, cost;
    cin >> party >> cost;

    voters[party].push_back(cost);
  }

  for (int i = 1; i <= partyc; i++) {
    sort(voters[i].begin(), voters[i].end(), greater<llong> ());

    for (int j = (int) voters[i].size() - 1; j >= 0; j--) {
      cost_to[i][j] = cost_to[i][j + 1] + voters[i][j];
    }

    for (int j = 0; j < (int) voters[i].size(); j++) {
      if (i != 1) {
        all_voters.push_back(make_pair(voters[i][j], make_pair(i, j)));
      }
    }
  }

  sort(all_voters.begin(), all_voters.end());

  llong ans = 1LL << 60;
  for (int i = 0; i < voterc; i++) {
    ans = min(ans, cost_with(i));
  }
  cout << ans << endl;
}