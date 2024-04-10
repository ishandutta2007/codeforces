#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX_NB_APPS = 300 * 1000 + 42;

vector<int> unreads[MAX_NB_APPS];
vector<bool> isRead;

int main() {
	int nbApps, nbEvents;
	cin >> nbApps >> nbEvents;
	
	int nbUnread = 0, lastRead = 0;
	for(int iEvent = 0;iEvent < nbEvents;iEvent++) {
		int type, arg;
		cin >> type >> arg;
		
		if(type == 1) {
			unreads[arg].push_back(isRead.size());
			isRead.push_back(false);
			nbUnread++;
		}
		else if(type == 2) {
			for(int id : unreads[arg]) {
				if(!isRead[id]) {
					isRead[id] = true;
					nbUnread--;
				}
			}
			unreads[arg].clear();
		}
		else if(type == 3) {
			int nbFois = arg - lastRead;
			for(int iFois = 0;iFois < nbFois;iFois++) {
				if(!isRead[lastRead]) {
					isRead[lastRead] = true;
					nbUnread--;
				}
				lastRead++;
			}
		}
		
		cout << nbUnread << endl;
	}
	return 0;
}