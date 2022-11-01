#include <iostream>
#include <string>
char line1[14]="0123456789abc",line2[14] = "0123456789abc";
void pos(int positon,char value) {
	int posi = positon;
	if (positon < 13) {
		line1[posi]= value;
	}
	else {
		line2[25- posi]=value;
	}
}
using namespace std;
int main()
{
	string line;
	cin >> line;
	int letters[26],first,second;
	for (int i = 0; i < 26; i++) {
		letters[i] = -1;
	}
	for (int i = 0; i < 27; i++) {
		int c = line[i] - 'A';
		if (letters[c] == -1) {
			letters[c] = i;
		}
		else {
			first = letters[c];
			second = i;
			break;
		}
	}
	if (second - first == 1) {
		cout << "Impossible\n";
		return 0;
	}
	if (first != 0) {
		line = line.substr(first, 27 - first) + line.substr(0, first);
		second -= first;
	}
	int positon = 13 - (second+1) / 2;
	for (int i = 0; i < 27; i++) {
		if (i == second) {
			continue;
		}
		pos(positon, line[i]);
		positon++;
		if (positon > 25) {
			positon = 0;
		}
	}
	cout << line1 << "\n";
	cout << line2 << "\n";
	return 0;
}