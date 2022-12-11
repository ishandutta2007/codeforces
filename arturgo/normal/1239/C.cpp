#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#define int long long
using namespace std;

const int BACK = 1;
const int HUNGRY = 0;

int tempsTotal[100000];

struct Event {
	int temps, id, type;
};

bool operator < (const Event & a, const Event & b) {
	if(a.temps != b.temps)
		return a.temps > b.temps;
	if(a.type != b.type)
		return a.type > b.type;
	return a.id > b.id;
}

set<int> peopleGone;
set<int> peopleWaiting;
deque<int> file;

priority_queue<Event> events;

signed main() {
	ios_base::sync_with_stdio(false);
	
	int nbPersonnes, p;
	cin >> nbPersonnes >> p;

	for(int iPersonne = 0;iPersonne < nbPersonnes;iPersonne++) {
		int temps;
		cin >> temps;
		events.push({temps, iPersonne, HUNGRY});
	}
	
	while(!events.empty()) {
		Event event = events.top();
		events.pop();

		if(event.type == HUNGRY) {
			peopleWaiting.insert(event.id);
		}
		else if(event.type == BACK) {
			peopleGone.erase(event.id);
			file.pop_front();

			tempsTotal[event.id] = event.temps;

			if(!file.empty()) {
				events.push({event.temps + p, file.front(), BACK});
			}
		}

		while(!peopleWaiting.empty() && (peopleGone.empty() || *peopleWaiting.begin() < *peopleGone.begin())) {
			peopleGone.insert(*peopleWaiting.begin());
			file.push_back(*peopleWaiting.begin());
			if(file.size() == 1) {
				events.push({event.temps + p, *peopleWaiting.begin(), BACK});
			}
			peopleWaiting.erase(peopleWaiting.begin());
		}
	}

	for(int iPersonne = 0;iPersonne < nbPersonnes;iPersonne++) {
		cout << tempsTotal[iPersonne] << " ";
	}
	cout << endl;

	return 0;
}