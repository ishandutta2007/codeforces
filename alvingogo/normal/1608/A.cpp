#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=2;i<n+2;i++){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}