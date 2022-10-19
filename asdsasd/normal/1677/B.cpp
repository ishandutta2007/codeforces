#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> S(n * m);
	char s;
	for(int i = 0; i < n * m; i++){
		cin >> s;
		S[i] = int(s - '0');
	}
	vector<int> ans(n * m);
	vector<int> cum(n * m);
	cum[0] = S[0];
	for(int i = 1; i < n * m; i++){
		cum[i] = cum[i - 1] + S[i];
	}
	for(int i = 0; i < m; i++){
		if(cum[i] > 0) ans[i] = 1;
	}
	for(int i = m; i < n * m; i++){
		ans[i] = ans[i - m];
		if(cum[i] - cum[i - m] > 0) ans[i]++;
	}
	vector<bool> col(m, false);
	int tot = 0;
	int j = 0;
	for(int i = 0; i < n * m; i++){
		if(S[i] == 1){
			if(!col[j]){
				col[j] = true;
				tot++;
			}
		}
		ans[i] += tot;
		j++;
		if(j == m) j = 0;
	}
	for(int i = 0; i < n * m; i++){
		cout << ans[i];
		if(i == (n * m - 1)) cout << "\n";
		else cout << " ";
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}