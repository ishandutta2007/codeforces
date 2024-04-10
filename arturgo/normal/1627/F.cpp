#include <iostream>
#include <queue>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

struct Event {
	int dist, lig, col;
};

bool operator < (const Event& a, const Event& b) {
	return a.dist > b.dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbPaires, cote;
		cin >> nbPaires >> cote;
		
		vector<vector<bool>> estPasse(cote + 1, vector<bool>(cote + 1, false));
		
		vector<vector<int>> dists(cote + 1, vector<int>(cote + 1, INFINI));
		
		vector<vector<vector<int>>> couts(cote + 1, vector<vector<int>>(cote + 1,
			vector<int>(4, 0)
		));
		
		for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			r1--; c1--; r2--; c2--;
			
			if(r1 == r2) {
				if(c1 > c2) swap(c1, c2);
				
				couts[r2][c2][0]++;
				couts[r2 + 1][c2][2]++;
				couts[cote - r2][cote - c2][2]++;
				couts[cote - (r2 + 1)][cote - c2][0]++;
			}
			else  {
				if(r1 > r2) swap(r1, r2);
				
				couts[r2][c2][1]++;
				couts[r2][c2 + 1][3]++;
				couts[cote - r2][cote - c2][3]++;
				couts[cote - r2][cote - (c2 + 1)][1]++;
			}
		}
		
		priority_queue<Event> events;
		events.push({0, cote / 2, cote / 2});
		
		while(!events.empty()) {
			Event cur = events.top();
			events.pop();
			
			if(cur.lig == 0 || cur.col == 0 || cur.lig == cote || cur.col == cote)  {
				cout << nbPaires - cur.dist << endl;
				break;
			}
			
			if(dists[cur.lig][cur.col] != INFINI)
				continue;
			dists[cur.lig][cur.col] = cur.dist;
			
			for(int iDir = 0;iDir < 4;iDir++) {
				events.push({cur.dist + couts[cur.lig][cur.col][iDir], cur.lig + dirs[iDir][0], cur.col + dirs[iDir][1]});
			}
		}
	}
	return 0;
}