#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, x;
int w[111];
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> x;
		rep(i, n) cin >> w[i];
		sort(w, w + n);
		int sum = 0;
		ans.clear();
		bool ok = 1;
		rep(i, n){
			if(sum + w[i] == x){
				if(i + 1 >= n){
					ok = 0;
					break;
				}
				ans.push_back(w[i + 1]);
				ans.push_back(w[i]);
				sum += w[i], sum += w[i + 1];
				i++;
			} else {
				sum += w[i];
				ans.push_back(w[i]);
			}
		}
		if(!ok) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			rep(i, (int)ans.size()) cout << ans[i] <<" ";
			cout << endl;
		}
	}
	return 0;
}