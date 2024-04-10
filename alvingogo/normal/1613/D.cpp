#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=998244353;
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
		vector<long long> dpk(n+2),dpl(n+2);
		dpk[0]=1;
		for(int i=0;i<n;i++){
			if(v[i]>0){
				ans+=dpk[v[i]-1]+dpl[v[i]-1];
				dpl[v[i]-1]+=dpk[v[i]-1]+dpl[v[i]-1];
				dpl[v[i]-1]%=mod;
			}
			long long x=dpk[v[i]+1]+dpl[v[i]+1];
			ans+=x;
			dpl[v[i]+1]+=dpl[v[i]+1];
			dpk[v[i]+1]+=dpk[v[i]+1];
			dpk[v[i]+1]%=mod;
			dpl[v[i]+1]%=mod;
			
			ans+=dpk[v[i]];
			dpk[v[i]+1]+=dpk[v[i]];
			dpk[v[i]+1]%=mod;
			ans%=mod;
		}
		cout << ans << "\n";
	}
	return 0;
}