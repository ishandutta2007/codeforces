#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int from[100100], to[100100];
vector<int> e[100100];
int ans[100100];

int main(){
	scanf("%d", &n);
	rep(i, n-1){
		scanf("%d%d", &from[i], &to[i]);
		from[i]--, to[i]--;
		e[from[i]].push_back(i);
		e[to[i]].push_back(i);
	}
	rep(i, n){
		if(e[i].size() > 2){
			ans[e[i][0]] = 1;
			ans[e[i][1]] = 2;
			ans[e[i][2]] = 3;
			int cnt = 4;
			rep(j, n-1){
				if(ans[j] == 0) ans[j] = cnt++;
			}
			rep(i, n-1) cout << ans[i] - 1 << endl;
			return 0;
		}
	}
	rep(i, n-1) cout << i << endl;
	return 0;
}