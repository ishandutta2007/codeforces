#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[111];
int dept[111];
void solve(int l, int r, int d){
	if(l > r) return ;
	int mxpos = l;
	for(int i = l; i <= r; i++) if(a[i] > a[mxpos]) mxpos = i;
	dept[mxpos] = d;
	solve(l, mxpos - 1, d + 1);
	solve(mxpos + 1, r, d + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i];
		solve(0, n-1, 0);
		rep(i, n) cout << dept[i] << " ";
		cout << endl;
	}
	return 0;
}