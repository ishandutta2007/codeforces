#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

vector<pair<int, int>> pauses;
int reponses[300000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbPauses, nbMinutes, minInter;
  cin >> nbPauses >> nbMinutes >> minInter;

  for(int iPause = 0;iPause < nbPauses;iPause++) {
    int pause;
    cin >> pause;
    pauses.push_back({pause, iPause});
  }

  sort(pauses.begin(), pauses.end());

  list<pair<int, int>> ouverts;

  int iJour = 0;
  for(pair<int, int> paire : pauses) {
    int pause = paire.first;
    int iPause = paire.second;
    if(!ouverts.empty() && ouverts.front().first + minInter < pause ) {
      int id = ouverts.front().second;
      ouverts.pop_front();
      ouverts.push_back({pause, id});
    }
    else {
      ouverts.push_back({pause, ++iJour});
    }
    reponses[iPause] = ouverts.back().second;
  }

  cout << ouverts.size() << endl;

  for(int iPause = 0;iPause < nbPauses;iPause++) {
    cout << reponses[iPause] << " ";
  }
  cout << endl;
  return 0;
}