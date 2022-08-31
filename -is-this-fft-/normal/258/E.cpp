#include <iostream>
#include <map>
#include <vector>

const int BLOCK = 320;
const int MAX_LENGTH = 100005;

using namespace std;

vector<int> adj [MAX_LENGTH];
vector<int> ops [MAX_LENGTH];
int range_start [MAX_LENGTH], range_end [MAX_LENGTH], cur_inx;

void find_ranges (int vertex, int parent) {
  range_start[vertex] = cur_inx;
  cur_inx++;

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      find_ranges(adj[vertex][i], vertex);
    }
  }

  range_end[vertex] = cur_inx;
}

int cur_ans, vertexc;
int cnt [BLOCK][MAX_LENGTH], incr [BLOCK], arr [MAX_LENGTH];
void add (int left, int right, int val) {
  right--;

  if (left / BLOCK == right / BLOCK) {
    if (incr[left / BLOCK] == 0) {
      cur_ans -= cnt[left / BLOCK][0];
    }

    for (int i = left; i <= right; i++) {
      cnt[left / BLOCK][arr[i]]--;
      arr[i] += val;
      cnt[left / BLOCK][arr[i]]++;
    }

    if (incr[left / BLOCK] == 0) {
      cur_ans += cnt[left / BLOCK][0];
    }
  } else {
    if (incr[left / BLOCK] == 0) {
      cur_ans -= cnt[left / BLOCK][0];
    }

    for (int i = left; i / BLOCK == left / BLOCK; i++) {
      cnt[left / BLOCK][arr[i]]--;
      arr[i] += val;
      cnt[left / BLOCK][arr[i]]++;
    }

    if (incr[left / BLOCK] == 0) {
      cur_ans += cnt[left / BLOCK][0];
    }
    
    if (incr[right / BLOCK] == 0) {
      cur_ans -= cnt[right / BLOCK][0];
    }

    for (int i = right; i / BLOCK == right / BLOCK; i--) {
      cnt[right / BLOCK][arr[i]]--;
      arr[i] += val;
      cnt[right / BLOCK][arr[i]]++;
    }

    if (incr[right / BLOCK] == 0) {
      cur_ans += cnt[right / BLOCK][0];
    }

    for (int i = left / BLOCK + 1; i < right / BLOCK; i++) {
      if (incr[i] == 0) {
        cur_ans -= cnt[i][0];
      }

      incr[i] += val;

      if (incr[i] == 0) {
        cur_ans += cnt[i][0];
      }
    }
  }
}

int ans [MAX_LENGTH];
void dfs (int vertex, int parent) {
  for (int i = 0; i < (int) ops[vertex].size(); i++) {
    add(range_start[ops[vertex][i]], range_end[ops[vertex][i]], 1);
    add(range_start[vertex], range_end[vertex], 1);
  }

  if (arr[range_start[vertex]] > 0 || incr[range_start[vertex] / BLOCK] > 0) {
    ans[vertex] = vertexc - cur_ans - 1;
  } else {
    ans[vertex] = vertexc - cur_ans;
  }

  for (int i = 0; i < (int) adj[vertex].size(); i++) {
    if (adj[vertex][i] != parent) {
      dfs(adj[vertex][i], vertex);
    }
  }

  for (int i = 0; i < (int) ops[vertex].size(); i++) {
    add(range_start[ops[vertex][i]], range_end[ops[vertex][i]], -1);
    add(range_start[vertex], range_end[vertex], -1);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int queryc;
  cin >> vertexc >> queryc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    ops[u].push_back(v);
    ops[v].push_back(u);
  }

  for (int i = 0; i < vertexc; i++) {
    cur_ans++;
    cnt[i / BLOCK][0]++;
  }

  find_ranges(1, 0);
  dfs(1, 0);

  for (int i = 1; i <= vertexc; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}