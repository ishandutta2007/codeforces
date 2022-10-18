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
	int tq;
	cin >> tq;
	while(tq--){
		int n;
		long long x;
		cin >> n;
		vector<long long> v(n+1);
		for(int i=1;i<=n;i++){
			cin >> v[i];
		}
		cin >> x;
		for(int i=1;i<=n;i++){
			v[i]-=x;
		}
		for(int i=1;i<=n;i++){
			v[i]+=v[i-1];
		}
		vector<bool> b(n+5);
		int ans=n;
		for(int i=1;i<=n-1;i++){
			if(v[i+1]-v[i-1]<0 && !b[i] && !b[i+1]){
				b[i+1]=1;
				ans--;
			}
			if(i>1 && v[i+1]-v[i-2]<0 && !b[i] && !b[i+1] && !b[i-1]){
				b[i+1]=1;
				ans--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}