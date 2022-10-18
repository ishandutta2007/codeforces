#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		vector<long long> v(n);
		long long k=0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			k+=v[i];
		}
		if((2*k)%n){
			cout << 0 << "\n";
			continue;
		}
		k=(2*k)/n;
		sort(v.begin(),v.end());
		long long ans=0;
		for(int i=0;i<n-1;i++){
			ans+=upper_bound(v.begin()+i+1,v.end(),k-v[i])-lower_bound(v.begin()+i+1,v.end(),k-v[i]);
		}
		cout << ans << "\n";
	}
		
	return 0;
}