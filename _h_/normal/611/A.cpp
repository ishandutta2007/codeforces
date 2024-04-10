#include <iostream>
using namespace std;

int main(){
	int x;
	string s;
	cin >> x >> s >> s;
	if(s == "week"){
		cout << 52 + (x == 5 || x == 6) << endl;
	} else {
		cout << 12 - (x==31 ? 5 : x > 29 ? 1 : 0) << endl;
	}
}