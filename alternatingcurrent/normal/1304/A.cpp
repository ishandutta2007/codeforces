#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int T;
	cin >> T;
	rep(i, T){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if((y-x) % (a+b) == 0) cout << (y-x) / (a+b) << endl;
		else cout << "-1" << endl;
	} 
	return 0;
}