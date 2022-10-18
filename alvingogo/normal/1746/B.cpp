#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
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
		int l=0,r=n-1;
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		int ans=0;
		while(1){
			while(l<n && v[l]==0){
				l++;
			}
			while(r>=0 && v[r]==1){
				r--;
			}
			if(l>=r){
				break;
			}
			swap(v[l],v[r]);
			ans++;
		}
		cout << ans << "\n";
	}	
    return 0;
}