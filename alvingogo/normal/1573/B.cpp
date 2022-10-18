#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> o(n),e(n),mp(n);
		for(int i=0;i<n;i++){
			cin >> o[i];
		}
		for(int i=0;i<n;i++){
			cin >> e[i];
			mp[i]=max(mp[(i-1)*(i>0)],e[i]);
		}
		int minx=1000000;
		for(int i=0;i<n;i++){
			int j=lower_bound(mp.begin(),mp.end(),o[i])-mp.begin();
			minx=min(minx,j+i);
		}
		cout << minx << "\n";
	}
	return 0;
}