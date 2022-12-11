#include <iostream>
using namespace std;

bool doitRetourner[256];

int main() {
	string chaine;
	cin >> chaine;
	
	doitRetourner[(int)'a'] = true;
	doitRetourner[(int)'e'] = true;
	doitRetourner[(int)'i'] = true;
	doitRetourner[(int)'o'] = true;
	doitRetourner[(int)'u'] = true;
	doitRetourner[(int)'1'] = true;
	doitRetourner[(int)'3'] = true;
	doitRetourner[(int)'5'] = true;
	doitRetourner[(int)'7'] = true;
	doitRetourner[(int)'9'] = true;
	
	int count = 0;
	for(char car : chaine) {
		if(doitRetourner[(int)car])
			count++;
	}
	
	cout << count << endl;
	return 0;
}