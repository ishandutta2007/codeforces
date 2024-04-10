#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200005;

typedef long long ll;

ll outSum [MAX_N];
int outCnt [MAX_N];
ll inSum [MAX_N];
int inCnt [MAX_N];
vector<int> adj [MAX_N];

void calcInSum (int vertex, int parent) {
  inCnt[vertex] = 1;
  inSum[vertex] = 0;
  for (int child : adj[vertex]) {
    if (child != parent) {
      calcInSum(child, vertex);
      inCnt[vertex] += inCnt[child];
      inSum[vertex] += inSum[child] + inCnt[child];
    }
  }
}

void calcOutSum (int vertex, int parent) {
  ll outSumSum = outSum[vertex];
  for (int child : adj[vertex]) {
    if (child != parent) {
      outSumSum += inSum[child] + inCnt[child];
    }
  }

  for (int child : adj[vertex]) {
    if (child != parent) {
      outSum[child] = outSumSum - (inSum[child] + inCnt[child]) + outCnt[child];
      calcOutSum(child, vertex);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calcInSum(1, 1);
  for (int i = 1; i <= vertexc; i++) {
    outCnt[i] = vertexc - inCnt[i];
  }
  calcOutSum(1, 1);

  ll ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    ans = max(ans, outSum[i] + inSum[i]);
  }

  cout << ans + vertexc << '\n';
}