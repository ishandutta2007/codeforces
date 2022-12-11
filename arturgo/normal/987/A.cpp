#include <iostream>
#include <map>
using namespace std;

map<string, string> gems = {
  {"purple", "Power"},
  {"green", "Time"},
  {"blue", "Space"},
  {"orange", "Soul"},
  {"red", "Reality"},
  {"yellow", "Mind"}
};

int main() {
  int nbGems;
  cin >> nbGems;

  for(int iGem = 0;iGem < nbGems;iGem++) {
    string color;
    cin >> color;
    gems.erase(color);
  }

  cout << gems.size() << endl;
  for(pair<string, string> gem : gems) {
    cout << gem.second << endl;
  }

  return 0;
}