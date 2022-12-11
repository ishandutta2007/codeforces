#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		string a, b;
		cin >> a >> b;
		
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		int iB = 0;
		
		map<char, int> presents;
		
		for(char car : b) presents[car]++;
		
		for(char car : a) {
			if(iB == (int)b.size()) {
				break;
			}
			
			if(b[iB] == car) {
				iB++;
				presents[car]--;
			}
			else if(presents[car] != 0) {
				break;
			}
		}
		
		if(iB == (int)b.size()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}