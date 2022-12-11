#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<pair<long long, char>> points;

int main() {
	ios_base::sync_with_stdio(false);
	int nbPoints;
	cin >> nbPoints;
	
	points.push_back({-(long long)4000 * 1000 * 1000, 'G'});
	points.push_back({(long long)4000 * 1000 * 1000, 'G'});
	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		long long pos;
		char coul;
		
		cin >> pos >> coul;
		points.push_back({pos, coul});
	}
	
	sort(points.begin(), points.end());
	
	long long derRouge = -1, derBleu = -1;
	
	long long total = 0;
	
	for(int iPoint = 0;iPoint <= nbPoints;) {
		int idVert = iPoint;
		derBleu = derRouge = points[idVert].first;
		
		long long preRouge = (long long)4000 * 1000 * 1000, preBleu = (long long)4000 * 1000 * 1000; 
		long long maxDiffRouge = 0, maxDiffBleu = 0;
		do {
			iPoint++;
			char coul = points[iPoint].second;
			if(coul == 'R' || coul == 'G') {
				maxDiffRouge = max(maxDiffRouge, points[iPoint].first - derRouge);
				if(coul != 'G')
					derRouge = points[iPoint].first;
				preRouge = min(preRouge, points[iPoint].first);
			}
			if(coul == 'B' || coul == 'G') {
				maxDiffBleu = max(maxDiffBleu, points[iPoint].first - derBleu);
				if(coul != 'G')
					derBleu = points[iPoint].first;
				preBleu = min(preBleu, points[iPoint].first);
			}
		} while(points[iPoint].second != 'G');
		
		long long gDist = (long long)points[iPoint].first - points[idVert].first;
		
		if(idVert == 0 && iPoint == nbPoints + 1) {
			if(preBleu != (long long)4000 * 1000 * 1000) {
				total += derBleu - preBleu;
			}
			if(preRouge != (long long)4000 * 1000 * 1000) {
				total += derRouge - preRouge;
			}
		}
		else if(idVert == 0) {
			if(preBleu != (long long)4000 * 1000 * 1000) {
				total += points[iPoint].first - preBleu;
			}
			if(preRouge != (long long)4000 * 1000 * 1000) {
				total += points[iPoint].first - preRouge;
			}
		}
		else if(iPoint == nbPoints + 1) {
			total += -points[idVert].first + derBleu;
			total += -points[idVert].first + derRouge;
		}
		else if(maxDiffBleu + maxDiffRouge > gDist) {
			total += 3 * gDist - maxDiffBleu - maxDiffRouge;
		}
		else {
			total += 2 * gDist;
		}
	}
	
	cout << total << endl;
	return 0;
}