#include <iostream>
using namespace std;

int vals[100][100];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			cin >> vals[i][j];
		}
	}
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(vals[i][j] != 1) {
				bool ok = false;
				for(int k = 0;k < n;k++) {
					for(int l = 0;l < n;l++) {
						if(vals[i][j] == vals[i][k] + vals[l][j]) {
							ok = true;
						}
					}
				}
				
				if(!ok) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}