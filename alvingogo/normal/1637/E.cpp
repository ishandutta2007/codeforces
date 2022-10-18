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
		int n,m;
		cin >> n >> m;
		map<int,int> cnt;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		vector<vector<int> > ccnt(n+1);
		for(auto h:cnt){
			ccnt[h.sc].push_back(h.fs);
		}
		for(auto &h:ccnt){
			sort(h.begin(),h.end(),greater<int>());
		}
		set<pair<int,int> > s;
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			s.insert({a,b});
			s.insert({b,a});
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(auto h:ccnt[i]){
				for(int j=i;j>0;j--){
					for(auto z:ccnt[j]){
						if(h==z || s.find({h,z})!=s.end()){
							continue;
						}
						ans=max(ans,1ll*(h+z)*(i+j));
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}