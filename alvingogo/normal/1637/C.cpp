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
		long long ans=0;
		if(n==3){
			if(v[1]%2==1){
				cout << -1 << "\n";
			}
			else{
				cout << v[1]/2 << "\n";
			}
		}
		else{
			int flag=0;
			for(int i=1;i<n-1;i++){
				ans+=v[i]+v[i]%2;
				if(v[i]>=2){
					flag=1;
				}
			}
			if(flag==0){
				ans=-2;
			}
			cout << ans/2 << "\n";
		}
	}
	return 0;
}