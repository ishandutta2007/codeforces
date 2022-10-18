#include <iostream>
using namespace std;
int main(){
	int n,f=0,x,y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		if(x!=y) f=1;
	}
	if(f) cout << "Happy Alex";
	else cout << "Poor Alex";
}