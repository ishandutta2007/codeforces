#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
using namespace std;

int nbLigs, nbCols;
const int INFINI = 1000 * 1000 * 1000;

vector<pair<int, int>> points[2];

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		cin >> nbLigs >> nbCols;
		
		for(int iLig = 0;iLig < nbLigs;iLig++) {
			string ligne;
			cin >> ligne;
			
			for(int iCol = 0;iCol < nbCols;iCol++) {
				if(ligne[iCol] == '1') {
					points[(iLig + iCol) % 2].push_back(
						{iLig - iCol, iLig + iCol}
					); 
				}
			}	
		}
		
		int somme = 0;
		for(int iPoint = 0;iPoint < 2;iPoint++) {
			/*cout << "----" << endl;
			
			for(pair<int, int> pt : points[iPoint]) {
				cerr << pt.first << " " << pt.second << endl;
			}*/
			
			// Compute longest decreasing subsequence
			
			sort(points[iPoint].begin(), points[iPoint].end());
			
			map<int, int> bests;
			bests[INFINI] = 0;
			
			int maxi = 0;
			for(pair<int, int> pt : points[iPoint]) {
				int bestVal = bests.upper_bound(pt.second)->second + 1;
				
				auto it = bests.lower_bound(pt.second);
				while(it != bests.begin()) {
					it--;
					if(it->second > bestVal)
						break;
					
					bests.erase(it);
					it = bests.lower_bound(pt.second);
				}
				
				bests[pt.second] = bestVal;
				maxi = max(maxi, bestVal);
			}
			
			somme += maxi;
		}
		
		cout << somme << endl;
		points[0].clear();
		points[1].clear();
	}
	
	return 0;
}