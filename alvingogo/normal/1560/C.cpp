#include <iostream>
#include <cmath>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a=sqrt(n-1);
		if(n-a*a<=a){
			cout << n-a*a << " " << a+1 << "\n";
		}
		else{
			cout << a+1 << " " << 2*a-n+a*a+2 << "\n";
		}
	}
	return 0;
}