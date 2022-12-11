#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

map<string, int> scores;
map<string, int> scores2;
vector<pair<string, int> > actions;
set<string> aMaxi;

int main() {
	int nbLignes;
	cin >> nbLignes;
	
	for(int iLigne = 0;iLigne < nbLignes;iLigne++) {
		string nom; int score;
		cin >> nom >> score;
		
		actions.push_back(make_pair(nom, score));
		
		scores[nom] += score;
	}
	
	int maxi = 0;
	for(pair<string, int> score : scores) {
		maxi = max(maxi, score.second);
	}
	
	for(pair<string, int> score : scores) {
		if(score.second == maxi) {
			aMaxi.insert(score.first);
		}
	}
	
	for(pair< string, int > score : actions) {
		scores2[score.first] += score.second;
		
		if(scores2[score.first] >= maxi && aMaxi.find(score.first) != aMaxi.end()) {
			cout << score.first << endl;
			return 0;
		}
	}
	
	return 0;
}