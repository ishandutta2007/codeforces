#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m, k;
vector< pair<int, char> > ans;

void add_path(int len, char dir){
	if(len == 0) return ;
	if(k == 0) return ;
	if(k >= len){
		ans.push_back(make_pair(len, dir));
		k -= len;
	} else {
		ans.push_back(make_pair(k, dir));
		k = 0;
	}
}

int main(){
	cin >> n >> m >> k;
	if(2*((n-1)*m + n*(m-1)) < k){
		cout << "NO" << endl;
		return 0;
	}
	add_path(m-1, 'R');
	rep(i, m-1){
		add_path(n-1, 'D');
		add_path(n-1, 'U');
		add_path(1, 'L');
	}
	add_path(n-1, 'D');
	rep(i, n-1){
		add_path(m-1, 'R');
		add_path(m-1, 'L');
		add_path(1, 'U');
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}