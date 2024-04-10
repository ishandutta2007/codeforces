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
		vector<long double> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		int ans=9999;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zz=0;
				long double d=(v[j]-v[i])/(1.0*(j-i)); 
				for(int k=0;k<n;k++){
					if(k==i || k==j){
						continue;
					}
					if(v[k]!=(v[i]-d*(i-k))){
						zz++;
					}
				}
				ans=min(ans,zz);
			}
		}
		if(n==1){
			ans=0;
		}
		cout << ans << "\n";
	}
	return 0;
}