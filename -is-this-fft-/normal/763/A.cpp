#include <iostream>
#include <vector>
#include <stdlib.h>

const int MAX_VERT = 100005;

using namespace std;

int color [MAX_VERT], visc [MAX_VERT];

int main () {
  int vertexc;
  cin >> vertexc;
  
  vector<pair<int, int> > edges (vertexc - 1);
  for (int i = 0; i < vertexc - 1; i++) {
    cin >> edges[i].first >> edges[i].second;
  }

  for (int i = 1; i <= vertexc; i++) {
    cin >> color[i];
  }

  int stc = 0;
  for (int i = 0; i < vertexc - 1; i++) {
    if (color[edges[i].first] != color[edges[i].second]) {
      visc[edges[i].first]++;
      visc[edges[i].second]++;
      stc++;
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    if (visc[i] == stc) {
      cout << "YES" << endl << i << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}