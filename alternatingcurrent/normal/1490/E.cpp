#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
int a[200200];
int ind[200200];
bool cmp(int x, int y){
	return (a[x] < a[y]);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i];
		rep(i, n) ind[i] = i;
		sort(ind, ind + n, cmp);
		ll sum = 0;
		int st = 0;
		rep(i, n){
			if(sum < a[ind[i]]) st = i;
			sum += a[ind[i]];
		}
		int l = st;
		while(l >= 0 && a[ind[l]] == a[ind[st]]) l--;
		vector<int> ans;
		for(int i = l + 1; i < n; i++) ans.push_back(ind[i] + 1);
		sort(ans.begin(), ans.end());
		cout << (int)ans.size() << endl;
		rep(i, (int)ans.size()) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}