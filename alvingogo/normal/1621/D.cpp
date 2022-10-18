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
		int minx=2e9;
		long long sum=0;
		for(int i=0;i<2*n;i++){
			for(int j=0;j<2*n;j++){
				int h;
				cin >> h;
				if(i>=n && j>=n){
					sum+=h;
				}
				else if((i==n && j==0) || (i==2*n-1 && j==0) || (i==n && j==n-1) || (i==2*n-1 && j==n-1) || (j==n && i==0) || (j==2*n-1 && i==0) || (j==n && i==n-1) || (j==2*n-1 && i==n-1)){
					minx=min(minx,h);
				}
			}
		}
		cout << sum+minx << "\n";
	}
	return 0;
}