#include <iostream>

using namespace std;



int main() {
   	int h = 20000;
   	
   	int nb;
   	cin >> nb;
   	for(int i = 0;i < nb;i++) {
   		int d;
   		string dir;
   		cin >> d >> dir;
   		
   		if(h == 0 && dir != "North") {
			cout << "NO" << endl;
   			return 0;
		}
		
		if(h == 20000 && dir != "South") {
			cout << "NO" << endl;
   			return 0;
		}
   		
   		if(dir == "North") {
   			h += d;
   		}
   		else if(dir == "South") {
   			h -= d;
   		}
   		
   		if(h < 0 || h > 20*1000) {
   			cout << "NO" << endl;
   			return 0;
   		}
   	}
   	
   	if(h != 20*1000) {
   		cout << "NO" << endl;
   	}
   	else {
		cout << "YES" << endl;
	}
    return 0;
}