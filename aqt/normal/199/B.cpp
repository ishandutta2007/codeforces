
// Problem : B. Special Olympics
// Contest : Codeforces - Codeforces Round #125 (Div. 2)
// URL : https://codeforces.com/contest/199/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct circle{
	int x, y, r;
};

int x[2], y[2], r1[2], r2[2];
int sqr(int x){
	return x*x;
}

bool inside(circle c1, circle c2){
	if(sqr(c1.x-c2.x)+sqr(c2.y-c1.y) <= sqr(c1.r-c2.r) && c2.r >= c1.r){
		return 1;
	}
	return 0;
}

bool inter(circle c1, circle c2){
	if(!inside(c1, c2) && !inside(c2, c1) && sqr(c1.x-c2.x)+sqr(c2.y-c1.y) < sqr(c1.r+c2.r)){
		return 1;
	}
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i<2;i++){
		cin >> x[i] >> y[i] >> r1[i] >> r2[i];
	}
	int ans = 0;
	//int cntrdis2 = sqr(x[0]-x[1]) + sqr(y[0]-y[1]);
	for(int i = 0; i<2; i++){
		/*
		if(cntrdis2 <= sqr(r1[i^1]-r1[i])){	
			cout << "1x " << i << endl;
			ans++;
		}
		else if(cntrdis2 >= sqr(r1[i]+r2[i^1])){
			cout << "1 " << i << endl;
			ans++;
		}
		if(cntrdis2 <= sqr(r1[i^1]-r2[i])){
			cout << "2x " << i << endl;
			ans++;
		}
		else if(cntrdis2 >= sqr(r2[i]+r2[i^1])){
			cout << "2 " << i << endl;
			ans++;
		}
		*/
		circle crntbig = {x[i], y[i], r2[i]}, crntsmall = {x[i], y[i], r1[i]};
		circle otherbig = {x[i^1], y[i^1], r2[i^1]}, othersmall = {x[i^1], y[i^1], r1[i^1]};
		/*
		if(inside(crntsmall, othersmall)){
			ans++;
		}
		else if(!inter(crntsmall, otherbig) && !inter(crntsmall, othersmall)){
			ans++;
		}
		if(inside(crntbig, othersmall)){
			ans++;
		}
		else if(!inter(crntbig, otherbig) && !inter(crntbig, othersmall)){
			ans++;
		}
		*/
		if(!inter(crntsmall, otherbig) && !inter(crntsmall, othersmall) && !(!inside(crntsmall, othersmall) && inside(crntsmall, otherbig))){
			ans++;
		}
		if(!inter(crntbig, otherbig) && !inter(crntbig, othersmall) && !(!inside(crntbig, othersmall) && inside(crntbig, otherbig))){
			ans++;
		}
	}
	cout << ans;
}