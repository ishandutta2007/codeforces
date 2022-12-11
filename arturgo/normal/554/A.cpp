#include <iostream>
#include <set>
using namespace std;

set<string> possibles;

int main() {
	string cur;
	cin >> cur;
	
	for(int iPos = 0;iPos <= (int)cur.size();iPos++) {
		for(int car = 0;car < 26;car++) {
			string cpy = cur;
			
			string s = " ";
			s[0] = (char)(car + 'a');
			
			cpy = cpy.insert(iPos, s);
			possibles.insert(cpy);
		}
	}
	
	cout << possibles.size() << endl;
}