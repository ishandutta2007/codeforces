#include <iostream>
#include <vector>

using namespace std;

bool has_bit (int x, int i) {
  return !!(x & 1 << i);
}

const int MAX_BIT = 20;
const int MAX_LEN = 300005;

int arr [MAX_LEN];
int meets [MAX_BIT][MAX_BIT];
int reaches [MAX_LEN][MAX_BIT];
int ans [MAX_LEN];

struct Query {
  int l, r, id;

  Query () {}
  Query (int t_l, int t_r, int t_id) {
    l = t_l;
    r = t_r;
    id = t_id;
  }
};

vector<Query> queries [MAX_LEN];

int main () {
  ios::sync_with_stdio(false);
  
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < queryc; i++) {
    int l, r;
    cin >> l >> r;

    queries[l].push_back(Query(l, r, i));
  }

  for (int i = 0; i < MAX_BIT; i++) {
    for (int j = 0; j < MAX_BIT; j++) {
      meets[i][j] = MAX_LEN;
    }
  }

  for (int i = length; i >= 1; i--) {
    for (int j = 0; j < MAX_BIT; j++) {
      reaches[i][j] = MAX_LEN;
    }
    
    for (int j = 0; j < MAX_BIT; j++) {
      if (has_bit(arr[i], j)) {
        for (int k = 0; k < MAX_BIT; k++) {
          if (has_bit(arr[i], k)) {
            meets[j][k] = i;
            reaches[i][k] = i;
          }
        }
      }
    }

    for (int j = 0; j < MAX_BIT; j++) {
      if (!has_bit(arr[i], j)) {
        int first_meet = MAX_LEN;
        for (int k = 0; k < MAX_BIT; k++) {
          if (has_bit(arr[i], k)) {
            first_meet = min(meets[j][k], first_meet);
          }
        }

        if (first_meet < MAX_LEN) {
          for (int k = 0; k < MAX_BIT; k++) {
            if (!has_bit(arr[i], k)) {
              reaches[i][k] = min(reaches[i][k], reaches[first_meet][k]);
            }
          }
        }
      }
    }

    /* answer queries */
    for (Query &q : queries[i]) {
      for (int k = 0; k < MAX_BIT; k++) {
        if (has_bit(arr[q.r], k)) {
          ans[q.id] |= reaches[i][k] <= q.r;
        }
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    cout << (ans[i] ? "Shi" : "Fou") << '\n';
  }
}