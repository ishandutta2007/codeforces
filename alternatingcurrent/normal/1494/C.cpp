#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int T;
int n, m;
vector<int> b[2], p[2];
int ans = 0;
int cnt_match = 0;

void solve(int now){
	cnt_match = 0;
	rep(i, (int)p[now].size()) if(lower_bound(b[now].begin(), b[now].end(), p[now][i]) != b[now].end() && *lower_bound(b[now].begin(), b[now].end(), p[now][i]) == p[now][i]) cnt_match++;
	int res = cnt_match;
	rep(i, (int)p[now].size()){
		if(lower_bound(b[now].begin(), b[now].end(), p[now][i]) != b[now].end() && *lower_bound(b[now].begin(), b[now].end(), p[now][i]) == p[now][i]) cnt_match--;
		int pos = upper_bound(b[now].begin(), b[now].end(), p[now][i]) - b[now].begin();
		int last_pos = p[now][i] - pos;
		int last_ppos = upper_bound(p[now].begin(), p[now].end(), last_pos) - p[now].begin();
		res = qmax(res, cnt_match + i - last_ppos + 1);
	}
	ans += res;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 2) b[i].clear(), p[i].clear();
		rep(i, n){
			int bpos;
			cin >> bpos;
			if(bpos < 0) b[0].push_back(-bpos);
			else b[1].push_back(bpos);
		}
		reverse(b[0].begin(), b[0].end());
		rep(i, m){
			int ppos;
			cin >> ppos;
			if(ppos < 0) p[0].push_back(-ppos);
			else p[1].push_back(ppos);
		}
		reverse(p[0].begin(), p[0].end());
		ans = 0;
		solve(0), solve(1);
		cout << ans << endl;
	}
	return 0;
}