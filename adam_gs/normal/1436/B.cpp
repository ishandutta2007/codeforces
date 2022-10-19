#include <iostream>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int PIERW=1e4+7;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		
		rep(i, n) {
			rep(j, n) {
				if(i==j) cout << PIERW-1; 
				else if((i+1)%n==j) cout << 1;
				else cout << 0;
				cout << " ";
			}
			cout << '\n';
		}
	}
}