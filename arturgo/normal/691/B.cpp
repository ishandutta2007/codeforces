#include <iostream>
using namespace std;

char symetricals[19][2] = {
	{'A', 'A'},
	{'b', 'd'},
	{'d', 'b'},
	{'H', 'H'},
	{'I', 'I'},
	{'M', 'M'},
	{'O', 'O'},
	{'o', 'o'},
	{'p', 'q'},
	{'q', 'p'},
	{'T', 'T'},
	{'U', 'U'},
	{'V', 'V'},
	{'v', 'v'},
	{'W', 'W'},
	{'w', 'w'},
	{'X', 'X'},
	{'x', 'x'},
	{'Y', 'Y'}
};

int main() {
	string s;
	cin >> s;
	
	int debut = 0, fin = (int)s.size()-1;
	while(debut <= fin) {
		char good = '{';
		for(int iCouple = 0;iCouple < 19;iCouple++) {
			if(symetricals[iCouple][0] == s[debut]) {
				good = symetricals[iCouple][1];
			}
		}
		
		if(good != s[fin]) {
			cout << "NIE" << endl;
			return 0;
		}
		
		debut++;
		fin--;
	}
	
	cout << "TAK" << endl;
	return 0;
}