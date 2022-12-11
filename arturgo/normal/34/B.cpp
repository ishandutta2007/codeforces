#include <iostream>
#include <algorithm>
using namespace std;

int poireau[1000 * 1000];

int main() {
	int camembert, fraise;
	cin >> camembert >> fraise;
	
	for(int iGateau = 0;iGateau < camembert;iGateau++) {
		cin >> poireau[iGateau];
	}
	
	sort(poireau, poireau + camembert);
	
	long long miam = 0;
	
	for(int banane = 0;banane < fraise;banane++) {
		if(poireau[banane] < 0)
			miam += poireau[banane];
	}
	
	cout << -miam << endl;
}