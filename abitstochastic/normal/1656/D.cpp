#include<bits/stdc++.h>
using namespace std;

int main(){
	int T; cin >> T;
	while(T--){
		long long N; cin >> N; long long T = N , tms = 2;
		while(T % 2 == 0){T /= 2; tms *= 2;}
		if(T == 1){puts("-1"); continue;}
		cout << min(tms , T) << endl;
	}
	return 0;
}