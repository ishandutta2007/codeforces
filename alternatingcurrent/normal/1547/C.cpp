#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int k, n, m;
int a[111], b[111];
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> k >> n >> m;
		rep(i, n){
			cin >> a[i];
		}
		rep(i, m){
			cin >> b[i];
		}
		ans.clear();
		int i = 0, j = 0;
		bool ok = 1;
		while(i < n || j < m){
			while(i < n && a[i] == 0){
				k++;
				ans.push_back(a[i]);
				i++;
			}
			while(j < m && b[j] == 0){
				k++;
				ans.push_back(b[j]);
				j++;
			}
			if(i >= n && j >= m)
				break;
			if(j >= m || (i < n && a[i] < b[j])){
				if(a[i] > k){
					ok = 0;
					break;
				}
				ans.push_back(a[i]);
				i++;
			} else {
				if(b[j] > k){
					ok = 0;
					break;
				} 
				ans.push_back(b[j]);
				j++;
			}
		}
		if(!ok)
			cout << "-1" << endl;
		else {
			rep(ind, (int)ans.size())
				cout << ans[ind] << " ";
			cout << endl;
		}
	}
	return 0;
}