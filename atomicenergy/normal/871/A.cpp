#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--){
		
		long long x;
		cin >> x;
		
		if(x%4==0){
			cout << x/4 << endl;
		}
		if(x%4==1){
			if(x==1 || x==5) cout << -1 << endl;
			else cout << (x/4)-1 << endl;
		}
		if(x%4==2){
			if(x==2) cout << -1 << endl;
			else cout << x/4 << endl;
		}
		if(x%4==3){
			if(x==3 || x==7 || x==11) cout << -1 << endl;
			else cout << (x/4)-1 << endl;
		}
	}
	return 0;
}