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
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		if(v[n-2]>v[n-1]){
			cout << -1 << "\n";
			continue;
		}
		if(v[n-1]<0){
			int flag=0;
			for(int i=0;i<n-1;i++){
				if(v[i]>v[i+1]){
					flag=1;
					break;
				}
			}
			if(flag){
				cout << -1 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		else{
			cout << n-2 << "\n";
			for(int i=0;i<n-2;i++){
				cout << i+1 << " " << n-1 << " " << n << "\n";
			}
		}
	}
	return 0;
}