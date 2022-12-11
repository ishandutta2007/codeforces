#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int nbVoyages, coutSimple, coutLiaison, maxCartes, coutCarte;

map<pair<string, string>, int> routes;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbVoyages >> coutSimple >> coutLiaison >> maxCartes >> coutCarte;
	
	long long total = 0;
	
	string derFin = "";
	for(int iVoyage = 0;iVoyage < nbVoyages;iVoyage++) {
		string a, b;
		cin >> a >> b;
		
		string der = b, pre = a;
		if(b < a)
			swap(a, b);
		
		if(routes.find({a, b}) == routes.end())
			routes[{a, b}] = 0;
		if(derFin == pre) {
			routes[{a, b}] += coutLiaison;
			total += coutLiaison;
		}
		else {
			routes[{a, b}] += coutSimple;
			total += coutSimple;
		}
			
		derFin = der;
	}
	
	vector<int> couts;
	for(pair<pair<string, string>, int> route : routes) {
		couts.push_back(route.second);
	}
	
	sort(couts.begin(), couts.end());
	
	for(int iFois = 0;iFois < maxCartes;iFois++) {
		if(!couts.empty() && couts.back() > coutCarte) {
			total += coutCarte - couts.back();
			couts.pop_back();
		}
	}
	
	cout << total << endl;
	return 0;
}