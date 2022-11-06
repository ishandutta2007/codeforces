#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

void maxeq(int &m, int u){
	m = max(m, u);
}

void mineq(int &m, int u){
	m = min(m, u);
}

int main(){
	int mx[2][8], mn[2][8];
	rep(i,0,2) rep(j,0,8){
		mx[i][j] = -1;
		mn[i][j] = 100;
	}
	rep(i,0,8) rep(j,0,8){
		char t;
		scanf(" %c ",&t);
		if(t != '.'){
			maxeq(mx[t == 'B'][j], i);
			mineq(mn[t == 'B'][j], i);
		}
	}
	int a = 100, b = 100;
	rep(i,0,8){
		mineq(a, mn[0][i] < mn[1][i] ? mn[0][i] : 100);
		mineq(b, mx[1][i] > mx[0][i] ? 7-mx[1][i] : 100);
	}
	puts(a <= b ? "A" : "B");
}