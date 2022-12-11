#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int nbJoueurs;
	cin >> nbJoueurs;
	
	for(int iJoueur = 0;iJoueur < nbJoueurs;iJoueur++) {
		string avant;
		cin >> avant;
		int a, n;
		cin >> a >> n;
		
		if(a >= 2400 && n > a) {
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}