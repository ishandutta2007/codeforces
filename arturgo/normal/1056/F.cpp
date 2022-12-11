#include <iostream>
#include <cmath>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

const double INFINI = 1000. * 1000 * 1000 * 1000 * 1000 * 1000.;
vector<pair<int, int>> problemes;

double dyn[1001][101];

int main() {
  ios_base::sync_with_stdio(false);
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    problemes.clear();
    
    int nbProblemes;
    cin >> nbProblemes;

    double C, T;
    cin >> C >> T;

    for(int iProbleme = 0;iProbleme < nbProblemes;iProbleme++) {
      int diff, score;
      cin >> diff >> score;
      problemes.push_back({diff, score});
    }

    sort(problemes.begin(), problemes.end());
    reverse(problemes.begin(), problemes.end());
    
    int maxPoints = 0;

    for(int nbPoints = 0;nbPoints <= 10 * nbProblemes;nbPoints++) {
      for(int nbResolus = 0;nbResolus <= nbProblemes;nbResolus++) {
	dyn[nbPoints][nbResolus] = INFINI;
      }
    }

    dyn[0][0] = 0;
    
    for(int probleme = nbProblemes - 1;probleme >= 0;probleme--) {
      for(int nbPoints = 10 * nbProblemes;nbPoints >= problemes[probleme].second;nbPoints--) {
	for(int nbResolus = 1;nbResolus <= nbProblemes;nbResolus++) {
	  dyn[nbPoints][nbResolus] = min(dyn[nbPoints][nbResolus], dyn[nbPoints - problemes[probleme].second][nbResolus - 1] / 0.9 + problemes[probleme].first);
	}
      }
    }
    
    for(int nbResolus = 1;nbResolus <= nbProblemes;nbResolus++) {
      for(int nbPoints = 0;nbPoints <= 10 * nbProblemes;nbPoints++) {
	double minTAvec1 = dyn[nbPoints][nbResolus] / 0.9;
	
	double melTrain = max<double>(0, (sqrt(minTAvec1 * C) - 1) / C);

	double melT = minTAvec1 / (1 + C * melTrain) + melTrain;

	if(melT < T - 10 * nbResolus && maxPoints < nbPoints) {
	  maxPoints = nbPoints;
	}
      }
    }

    cout << maxPoints << endl;
  }

  return 0;
}