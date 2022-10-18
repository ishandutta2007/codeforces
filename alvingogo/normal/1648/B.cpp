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
		int n,c;
		cin >> n >> c;
		vector<int> v(n);
		vector<int> cnt(c+1);
		for(int i=0;i<n;i++){
			cin >> v[i];
			cnt[v[i]]++;
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int flag=0;
		if(v[0]!=1){
			cout << "No\n";
			continue;
		}
		for(auto i:v){
			int l=0;
			for(int j=1;i*j<=c;j++){
				if(cnt[j]==0){
					if(upper_bound(v.begin(),v.end(),i*(j+1)-1)-lower_bound(v.begin(),v.end(),i*j)){
						flag=1;
						break;
					}
				}	
			}
			if(flag){
				cout << "No\n";
				break;
			}
		}
		if(!flag){
			cout << "Yes\n";
		}
	}
	return 0;
}