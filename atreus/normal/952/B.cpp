#include <iostream>

using namespace std;

int main (){
	int p = 0;
	for (int i = 9; i >= 0; i--){
		cout << i << endl;
		string s;
		getline (cin, s);
		if (s == "no"){
			p ++;
			if (p > 3){
				return cout << "normal" << endl, 0;
			}
			continue;
		}
		if (s == "worse" or s == "terrible" or s == "go die in a hole" or s == "are you serious?" or s == "don't even" or s == "no way")
			return cout << "grumpy" << endl, 0;
		else
			return cout << "normal" << endl, 0;
	}
}