/*input

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

// start of code

const int64_t INF = 1e18;

string str;
int strPtr;

char curChar()
{
	while (str[strPtr] == ' ') ++strPtr;
	return str[strPtr];
}

char nextChar()
{
	while (str[strPtr] == ' ') ++strPtr;
	++strPtr;
	return curChar();
}

class Circuit
{
public:
	bool isSeries = 0;
	vector<Circuit*> children;
	int resistanceId = -1;
	int64_t weight = 0; // not actual weight, but square root of weight

	Circuit() { children.clear(); }
	void giveBirth();
	void initResistance();
	void initJoined();
	void build();
	void putResistance(int64_t);
};
Circuit root;
vector<int64_t> resistances;	

// start of helper functions

void Circuit::giveBirth()
{
	children.push_back(new Circuit());
	children.back()->build();
}

void Circuit::initResistance()
{
	children.clear();
	resistanceId = (int) resistances.size();
	resistances.emplace_back(0);
	weight = 1;
}

void Circuit::initJoined()
{
	children.clear();
	resistanceId = -1;

	assert(curChar() == '(');
	while (nextChar() != ')') {
		// cout << "curChar " << curChar() << endl;
		// cout << "childId A " << childIds.size() << endl;
		if (curChar() == 'S') isSeries = 1;
		else if (curChar() == 'P') isSeries = 0;
		else giveBirth();	
		// cout << "childId B " << childIds.size() << endl;
	}

	// calculate weight
	if (isSeries) {
		weight = INF;
		for (auto child : children) {
			if (weight > child->weight) {
				weight = child->weight;
			}
		}
	} else {
		weight = 0;
		for (auto child : children) {
			weight += child->weight;
		}
	}
}

void Circuit::build()
{
	// cout << "childId" << ' '<< childIds.size() << endl;
	// cout << "start build" << endl;
	if (curChar() == '*') {
		initResistance();
		// cout << "resistance" << endl;
	} else {
		initJoined();
	}
	// cout << "children ";
	// for (int id : childIds) cout << circuits[id].weight << ' ';
	// cout << endl;
	// cout << "weight " << weight << endl;
	// cout << "end build" << endl;
}

void Circuit::putResistance(int64_t totalCost)
{
	if (resistanceId >= 0) {
		resistances[resistanceId] = totalCost;
	} else if (isSeries) {
		auto favouriteChild = children[0];
		for (auto child : children) {
			if (child->weight < favouriteChild->weight) {
				favouriteChild = child;
			}
		}
		favouriteChild->putResistance(totalCost);
	} else {
		assert(totalCost % weight == 0);
		for (auto child : children) {
			child->putResistance(totalCost / weight * child->weight);
		}
	}
}

// end of declaration

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in.txt", "r", stdin);
	int noTests;
	cin >> noTests;
	
	while (noTests--) {
		int multiplier;
		cin >> multiplier;

		getline(cin, str);

		strPtr = 0;
		resistances.clear();

		root.build();
		root.putResistance(multiplier * root.weight * root.weight);

		cout << "REVOLTING ";
		for (int64_t resistance : resistances) {
			cout << resistance << ' ';
		}
		cout << '\n';
	}
	

	return 0;
}