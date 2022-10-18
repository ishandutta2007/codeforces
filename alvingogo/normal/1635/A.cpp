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
		int y=0;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			y|=a;
		}
		cout << y << "\n";
	}
	return 0;
}