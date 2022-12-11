#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

vector<pair<int, int>> obs, indices;
set<pair<int, int>> points;

int main() {
  ios_base::sync_with_stdio(false);
  int nb;
  cin >> nb;

  for(int i = 0;i < nb;i++) {
    int x, y;
    cin >> x >> y;
    obs.push_back({x, y});
  }

  for(int i = 0;i < nb;i++) {
    int a, b;
    cin >> a >> b;
    indices.push_back({a, b});
  }

  for(int i = 0;i < nb;i++) {
    pair<int, int> tres = {obs[0].first + indices[i].first, obs[0].second + indices[i].second};

    points.clear();
    for(int j = 0;j < nb;j++) {
      points.insert(obs[j]);
    }

    bool valide = true;
    for(int j = 0;j < nb;j++) {
      auto it = points.find({tres.first - indices[j].first, tres.second - indices[j].second});
      if(it == points.end()) {
	valide = false;
	break;
      }
      else {
	points.erase(it);
      }
    }

    if(valide) {
      cout << tres.first << " " << tres.second << endl;
      return 0;
    }
  }
  return 0;
}