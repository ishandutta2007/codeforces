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
		int n,k;
		cin >> n >> k;
		if(2*k>n+1){
			cout << -1 << "\n"; 
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j && i%2==0 && i<2*k){
					cout << "R";
				}
				else{
					cout << ".";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}