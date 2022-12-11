#include <iostream>
using namespace std;

int p[1000];

bool estPris[1000];

int main() {
	int n, m;
	cin >> n >> m;
	
	int derL;
	cin >> derL;
	
	for(int i = 1;i < m;i++) {
		int l;
		cin >> l;
		
		int dec = l - derL;
		
		while(dec <= 0)
			dec += n;
			
		if(estPris[dec] && p[derL] != dec) {
			cout << -1 << endl;
			return 0;
		}
		
		if(p[derL] != 0 && p[derL] != dec) {
			cout << -1 << endl;
			return 0;
		}
		
		p[derL] = dec;
		estPris[dec] = true;
		
		derL = l;
	}
	
	int cur = 1;
	
	for(int i = 1;i <= n;i++) {
		while(p[i] == 0) {
			if(!estPris[cur])
				p[i] = cur;
			cur++;
		}
		cout << p[i] << " ";
	}
	cout << endl;
}