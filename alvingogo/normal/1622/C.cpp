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
		long long k,sum=0;
		cin >> n >> k;
		vector<long long> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			sum+=v[i];
		}
		if(sum<=k){
			cout << 0 << "\n";
			continue;
		}
		if(n==1){
			cout << sum-k << "\n";
			continue;
		}
		sort(v.begin(),v.end(),greater<long long>());
		long long h=v[n-1];
		sum-=h;
		long long ans=1e18;
		for(int i=0;i<n;i++){
			long long r=(k-sum)/(i+1);
			if(k-sum<=0 && (k-sum)%(i+1)!=0){
				r--;
			}
			ans=min(ans,i+max(h-r,0ll));
			sum-=v[i];
		}
		cout << ans << "\n";
	}
	return 0;
}