#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T;
	for(cin >> T ; T ; --T){
		int R , N; long long S = 0;
		cin >> N; R = N;
		while(N--){int A; cin >> A; S += A;}
		cout << (S % R != 0) << endl;
	}
	return 0;
}