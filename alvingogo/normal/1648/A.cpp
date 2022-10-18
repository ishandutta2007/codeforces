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
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int> > > v(100005);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin >> a;
			v[a].push_back({i,j});
		}
	}
	long long ans=0;
	for(int i=1;i<=100000;i++){
		if(v[i].size()){
			long long sum=0,cnt=0;
			for(auto &h:v[i]){
				ans+=cnt*h.fs-sum;
				sum+=h.fs;
				cnt++;
				swap(h.fs,h.sc);
			}
			sort(v[i].begin(),v[i].end());
			sum=0;
			cnt=0;
			for(auto h:v[i]){
				ans+=cnt*h.fs-sum;
				sum+=h.fs;
				cnt++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}