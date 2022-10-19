#include<bits/stdc++.h>
// #include<atcoder/modint>
using namespace std;
// using namespace atcoder;

void solve(){
	int n;
	cin >> n;
	vector<int> P(n);
	for(int i = 0; i < n; i++) cin >> P[i];
	long long ans = 0;
	deque<pair<pair<int, int>, int>> vec;
	int tot = 0;
	for(int i = 0; i < n; i++){
		vector<pair<pair<int, int>, int>> cnt;
		tot++;
		while(!vec.empty()){
			auto tmp = vec.front();
			tot -= tmp.second;
			auto tt = tmp.first;
			vec.pop_front();
			pair<int, int> nex;
			nex.first = -1;
			nex.second = n + 1;
			bool ok = false;
			if(tt.second < P[i]){
				nex.first = P[i - 1];
				ok = true;
			}
			if(P[i] > P[i - 1]){
				if(tt.first > nex.first){
					nex.first = tt.first;
					ok = true;
				}
			}
			if(tt.first > P[i]){
				nex.second = P[i - 1];
				ok = true;
			}
			if(P[i] < P[i - 1]){
				if(tt.second < nex.second){
					nex.second = tt.second;
					ok = true;
				}
			}
			if(ok){
				tot += tmp.second;				
				if(!cnt.empty() && cnt[cnt.size() - 1].first == nex){
					cnt[cnt.size() - 1].second += tmp.second;
				}
				else{
					cnt.push_back({nex, tmp.second});
				}
			}
		}
		ans += tot;
		for(auto c:cnt){
			vec.push_back(c);
		}
		vec.push_back({{n + 1, -1}, 1});
	}
	cout << ans << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}