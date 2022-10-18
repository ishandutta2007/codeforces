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
		vector<int> v(101,0);
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			v[abs(a)]++;
		}
		int ans=0;
		for(int i=0;i<=100;i++){
			if(!i){
				ans+=(v[i]>0);
				continue;
			}
			if(v[i]>=2){
				ans+=2;
			}
			else{
				ans+=v[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}