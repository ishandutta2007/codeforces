#include <iostream>
#include <vector>
using namespace std;

int main() {
	string a;
	cin >> a;
	
	string b = a;
	
	for(int pos = (int)a.size() - 2;pos >= 0;pos--) {
		b[pos] = min(b[pos], b[pos + 1]);
	}
	
	vector<char> pile;
	
	for(int pos = 0;pos < a.size();pos++) {
		while(!pile.empty() && pile.back() <= b[pos]) {
			cout << pile.back();
			pile.pop_back();
		}
		
		if(a[pos] == b[pos]) {
			cout << a[pos];
		}
		else {
			pile.push_back(a[pos]);
		}
	}
	
	while(!pile.empty()) {
		cout << pile.back();
		pile.pop_back();
	}
	
	cout << endl;
}