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
		vector<int> d(n);
		vector<pair<int,int> > z;
		for(int i=0;i<n;i++){
			cin >> v[i];
			if(i){
				d[i]=v[i]-v[i-1];
				z.push_back({d[i],i});
			}
		}
		sort(z.begin(),z.end());
		vector<int> ans(n,1);
		int nw=n-1;
		for(auto h:z){
			ans[nw]=h.sc+1;
			nw--;
		}
		for(auto h:ans){
			cout << h << " ";
		}
		cout << "\n";
	}	
    return 0;
}