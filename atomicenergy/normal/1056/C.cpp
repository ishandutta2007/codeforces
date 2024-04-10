#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<pair<int, int>> chosen;
	vector<int> a;
	vector<int> p;
	for(int i=0; i<2*n; i++){
		
		int x;
		cin >> x;
		chosen.insert({x, i+1});
		p.push_back(x);
	}
	
	set<pair<int, int>> pairs;
	map<int, int> partner;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		pairs.insert({x, y});
		partner[x] = y;
		partner[y] = x;
	}
	int turn = 1;
	cin >> turn;
	int prev = -1;
	for(int i=0; i<2*n; i++){
		if(turn == 1){
			if(partner.count(prev) && chosen.count({p[partner[prev]-1], partner[prev]})){
				cout << partner[prev] << endl;
				pairs.erase({prev, partner[prev]});
				pairs.erase({partner[prev], prev});
				chosen.erase({p[partner[prev]-1], partner[prev]});
				cout.flush();
			}else{
				if(pairs.size() > 0){
					auto q = (*pairs.begin());
					pairs.erase(q);
					if(p[q.first-1] > p[q.second-1]){
						int tmp = q.first;
						q.first = q.second;
						q.second = tmp;
					}
					cout << q.second << endl;
					chosen.erase({p[q.second-1], q.second});
					cout.flush();
				}else{
					auto q = (*chosen.rbegin());
					cout << q.second << endl;
					chosen.erase(q);
					cout.flush();
				}
			}
		}else{
			int x;
			cin >> x;
			chosen.erase({p[x-1], x});
			prev = x;
		}
		turn = 3 - turn;
	}
	
	return 0;
}