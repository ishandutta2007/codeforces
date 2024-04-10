#include<bits/stdc++.h>
using namespace std;

int main(){
	long long T , X , N;
	for(cin >> T ; T ; --T){
		cin >> X >> N; long long T = N / 4 * 4;
		while(++T <= N) if(X % 2) X += T; else X -= T;
		cout << X << endl;
	}
	return 0;
}