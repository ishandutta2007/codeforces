#include <iostream>
#include <queue>

const int MAX_CITY = 200005;
const int INF = 1023456789;

using namespace std;

int dist [MAX_CITY];
int shc [MAX_CITY];

int main () {
  int cityc;
  
  cin >> cityc;
  for (int i = 1; i <= cityc; i++) {
    cin >> shc[i];
  }

  for (int i = 1; i <= cityc; i++) {
    dist[i] = INF;
  }
  
  queue<int> que;
  que.push(1);
  dist[1] = 0;

  while (!que.empty()) {
    int qtop = que.front();
    que.pop();

    if (dist[shc[qtop]] == INF) {
      dist[shc[qtop]] = dist[qtop] + 1;
      que.push(shc[qtop]);
    }

    if (qtop != cityc && dist[qtop + 1] == INF) {
      dist[qtop + 1] = dist[qtop] + 1;
      que.push(qtop + 1);
    }

    if (qtop != 1 && dist[qtop - 1] == INF) {
      dist[qtop - 1] = dist[qtop] + 1;
      que.push(qtop - 1);
    }
  }

  for (int i = 1; i <= cityc; i++) {
    cout << dist[i] << (i == cityc ? "\n" : " ");
  }
}