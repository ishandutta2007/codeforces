#include <iostream>
using namespace std;

string a[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
string b[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
bool mark[6];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 6; j++) {
			if (s == b[j])
				mark[j] = true;
		}
	}
	cout << 6 - n << endl;
	for (int i = 0; i < 6; i++) {
		if (!mark[i])
			cout << a[i] << endl;
	}
	return 0;
}