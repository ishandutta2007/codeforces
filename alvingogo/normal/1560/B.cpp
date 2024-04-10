#include <iostream>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int n=2*(a-b)*(2*(a>b)-1);
		if(a>n || b>n || n<0){
			cout << -1 << endl;
			continue;
		}
		if(c>n){
			cout << -1 << endl;
			continue;
		}
		if(c>n/2){
			cout << c-n/2 << endl;
		}
		else{
			cout << c+n/2 << endl;
		}
		
	}
	return 0;
}