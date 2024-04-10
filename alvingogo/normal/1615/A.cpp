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
		long long sum=0;
		for(int i=0;i<n;i++){
			int v;
			cin >> v;
			sum+=v;
		}
		if(sum%n==0){
			cout << 0 << "\n";
		}
		else{
			cout << 1 << "\n";
		}
	}
	return 0;
}