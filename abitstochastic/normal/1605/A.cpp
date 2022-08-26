#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , A , B , C;
	for(cin >> T ; T ; --T){
		cin >> A >> B >> C;
		cout << ((A + C - 2 * B) % 3 == 0 ? 0 : 1) << endl;
	}
	return 0;
}