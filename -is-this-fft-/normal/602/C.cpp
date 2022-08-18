#include <iostream>
#define MAX_T 405
#define INF 1000000000

using namespace std;

bool railway [405][405];
long long dist [405][405];

int main () {
  int townc, railc;
  cin >> townc >> railc;
  for (int i = 0; i < railc; i++) {
    int u, v;
    cin >> u >> v;
    railway[u][v] = true;
    railway[v][u] = true;
  }

  if (railway[1][townc]) {
    for (int i = 1; i <= townc; i++) {
      for (int j = 1; j <= townc; j++) {
	if (i == j) dist[i][j] = 0;
	else if (railway[i][j]) dist[i][j] = INF;
	else dist[i][j] = 1;
      }
    }
  } else {
    for (int i = 1; i <= townc; i++) {
      for (int j = 1; j <= townc; j++) {
	if (i == j) dist[i][j] = 0;
	else if (railway[i][j]) dist[i][j] = 1;
	else dist[i][j] = INF;
      }
    }
  }

  /*r (int i = 1; i <= townc; i++) {
    for (int j = 1; j <= townc; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
    }*/
  
  for (int k = 1; k <= townc; k++) {
    for (int i = 1; i <= townc; i++) {
      for (int j = 1; j <= townc; j++) {
	if (dist[i][j] > dist[i][k] + dist[k][j]) {
	  dist[i][j] = dist[i][k] + dist[k][j];
	}
      }
    }
  }

  cout << (dist[1][townc] >= INF ? -1 : dist[1][townc]) << endl;
}