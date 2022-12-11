#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Triple {
	int taille, prix, id;
	Triple(int _taille, int _prix, int _id) {
		taille = _taille;
		prix = _prix;
		id = _id;
	}
	Triple() {}
};

bool operator < (const Triple &a, const Triple &b) {
	if(a.taille != b.taille)
		return a.taille < b.taille;
	return a.prix > b.prix;
}

int nbPaires, nbClients;
vector<Triple> paires;
vector<Triple> clients;
map<int, int> tailles;

map<pair<int, int>, long long> dyn;
vector<pair<int, int>> solution;

long long maxProfit(int client = 0, int paire = 0) {
	if(client >= nbClients)
		return 0;
	
	paire = max(paire, tailles.lower_bound(clients[client].taille)->second);
	if(paire >= nbPaires)
		return 0;
	
	int delta = paires[paire].taille - clients[client].taille;
	
	if(dyn.find({client, paire}) != dyn.end())
		return dyn[{client, paire}];
	
	long long profit = maxProfit(client + 1, paire);
	
	if(delta <= 0)
		profit = max(profit, maxProfit(client, paire + 1));
	
	if(delta == 0 || delta == 1) {
		if(paires[paire].prix <= clients[client].prix)
			profit = max(profit, maxProfit(client + 1, paire + 1) + paires[paire].prix);
	}
	
	if(delta == 0
	&& client != nbClients - 1 
	&& paire != nbPaires - 1
	&& paires[paire + 1].taille == clients[client].taille + 1
	&& clients[client + 1].taille == clients[client].taille
	&& clients[client].prix >= paires[paire + 1].prix
	&& clients[client + 1].prix >= paires[paire].prix) {
		profit = max(profit, maxProfit(client + 2, paire + 2) + paires[paire].prix + paires[paire + 1].prix);
	}
	
	dyn[{client, paire}] = profit;
	return profit;
}

void creeSolution(int client = 0, int paire = 0) {
	if(client >= nbClients)
		return;
	paire = max(paire, tailles.lower_bound(clients[client].taille)->second);
	if(paire >= nbPaires)
		return;
	
	if(maxProfit(client, paire) == maxProfit(client + 1, paire))
		creeSolution(client + 1, paire);
	else if(maxProfit(client, paire) == maxProfit(client, paire + 1))
		creeSolution(client, paire + 1);
	else if(maxProfit(client, paire) == maxProfit(client + 1, paire + 1) + paires[paire].prix && paires[paire].prix <= clients[client].prix) {
		solution.push_back({client, paire});
		creeSolution(client + 1, paire + 1);
	}
	else {
		solution.push_back({client, paire + 1});
		solution.push_back({client + 1, paire});
		creeSolution(client + 2, paire + 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbPaires;
	
	for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
		int prix, taille;
		cin >> prix >> taille;
		paires.push_back(Triple(taille, prix, iPaire));
	}
	tailles[2000 * 1000 * 1000] = nbPaires;
	
	cin >> nbClients;
	
	for(int iClient = 0;iClient < nbClients;iClient++) {
		int argent, taille;
		cin >> argent >> taille;
		clients.push_back(Triple(taille, argent, iClient));
	}
	
	sort(paires.begin(), paires.end());
	sort(clients.begin(), clients.end());
	
	for(int iPaire = 0;iPaire < nbPaires;iPaire++) {
		tailles[paires[iPaire].taille] = iPaire;
	}
	
	cout << maxProfit() << endl;
	
	creeSolution();
	cout << solution.size() << endl;
	for(pair<int, int> paire : solution) {
		cout << clients[paire.first].id + 1 << " " << paires[paire.second].id + 1 << endl;
	}
	return 0;
}