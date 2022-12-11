#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

vector< vector<int> > cycles;

void construitSolution(int taille) {
	if(taille == 3) {
		cycles.push_back({1, 2, 3});
		cycles.push_back({1, 2, 3});
		return;
	}
	if(taille == 4) {
		cycles.push_back({2, 3, 4});
		cycles.push_back({1, 3, 4});
		cycles.push_back({1, 2, 4});
		cycles.push_back({1, 2, 3});
		return;
	}
	
	construitSolution(taille - 2);
	
	for(int iAutre = 1;iAutre <= taille - 3;iAutre += 2) {
		cycles.push_back({iAutre, taille, iAutre + 1, taille - 1});
		cycles.push_back({iAutre, taille, iAutre + 1, taille - 1});
	}
	
	if(taille % 2 == 1) {
		cycles.push_back({taille, taille - 2, taille - 1});
		cycles.push_back({taille, taille - 2, taille - 1});
	}
	else {
		cycles.pop_back();
		
		cycles.push_back({taille, taille - 2, taille - 1});
		cycles.push_back({taille, taille - 3, taille - 1});
	}
}

int main() {
	int taille;
	cin >> taille;
	
	construitSolution(taille);
	
	cout << cycles.size() << endl;
	for(vector<int> cycle : cycles) {
		cout << cycle.size() << " ";
		
		for(int elem : cycle) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}