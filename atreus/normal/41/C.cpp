
#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string s;
	cin >> s;
	bool atiscome = false;
	for (int i = 0; i < s.size(); i++){
		if (i > 0 && i < s.size() - 2){
			if (i < s.size() - 3 && i < s.size() - 1 && s.substr(i, 3) == "dot"){
				cout << '.';
				i += 2;
			}
			else if (i < s.size() - 2 && s.substr(i, 2) == "at" && !atiscome){
				cout << '@';
				i ++;
				atiscome = true;
			}
			else
				cout << s[i];
		}
		else
			cout << s[i];
	}
	cout << endl;
}