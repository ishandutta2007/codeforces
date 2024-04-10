#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T;
	for(cin >> T ; T ; --T){
		int x1 , y1 , x2 = 0 , y2 = 0; cin >> x1 >> y1;
		if((abs(x1 - x2) + abs(y1 - y2)) % 2){cout << "-1 -1\n";}
		else{
			if(x1 > x2) swap(x1 , x2);
			if(y1 > y2) swap(y1 , y2);
			int P = x1 + (x2 - x1) / 2 , Q = y1 + (y2 - y1 + 1) / 2;
			cout << P << ' ' << Q << endl;
		}
	}
	return 0;
}