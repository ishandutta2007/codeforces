#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int nbTest;
	cin >> nbTest;
 
	for(int iTest = 0;iTest < nbTest;iTest++) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
 
		string chaine;
		cin >> chaine;
 
		string sol = "";
		int nbWins = 0;
		for(char car : chaine) {
			if(car == 'R' && b != 0) {
				b--;
				sol.push_back('P');
				nbWins++;
			}
			else if(car == 'S' && a != 0) {
				a--;
				sol.push_back('R');
				nbWins++;
			}
			else if(car == 'P' && c != 0) {
				c--;
				sol.push_back('S');
				nbWins++;
			}
			else 
				sol.push_back('*');
		}
 
		if(2 * nbWins >= n) {
			cout << "YES" << endl;
 
			for(char& car : sol) {
				if(car == '*') {
					if(a != 0) {
						car = 'R';
						a--;
					}
					else if(b != 0) {
						car = 'P';
						b--;
					}
					else if(c != 0) {
						car = 'S';
						c--;
					}
				}
			}
 
			cout << sol << endl;
		}
		else {
			cout << "NO" << endl;
		}
 
	}
	return 0;
}