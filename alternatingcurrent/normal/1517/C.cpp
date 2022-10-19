#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int p[555];
int inp[555];
set< pair<int, int> > st;
int ans[555][555];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) cin >> p[i], p[i]--;
	rep(i, n) inp[p[i]] = i;
	for(int mx = n - 1; mx >= 0; mx--){
		st.insert(make_pair(inp[mx], mx));
		int nowpos = 0;
		for(set< pair<int, int> >::iterator it = st.begin(); it != st.end(); it++, nowpos++){
			ans[mx + nowpos][nowpos] = it->second;
		}
	}
	rep(i, n){
		rep(j, i + 1) cout << ans[i][j] + 1 << " ";
		cout << endl;
	}
	return 0;
}