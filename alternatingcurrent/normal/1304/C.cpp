#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int n, m;
int t[111], l[111], r[111];
int now_l, now_r;

int main(){
	int Q;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d %d", &n, &m);
		t[0] = 0;
		rep(i, n){
			scanf("%d %d %d", &t[i], &l[i], &r[i]);
		} 
		now_l = m, now_r = m;
		bool ok = 1;
		rep(i, n){
			now_l -= (t[i] - t[i-1]);
			now_r += (t[i] - t[i-1]);
			now_l = qmax(now_l, l[i]);
			now_r = qmin(now_r, r[i]);
			if(now_l > now_r){
				cout << "NO" << endl;
				ok = 0;
				break;
			}
		} 
		if(ok) cout << "YES" << endl;
	}
	return 0;
}