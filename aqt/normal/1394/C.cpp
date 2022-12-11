
// Problem : C. Boboniu and String
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

#define test(x, y) if(func(x, y)) return make_pair(x, y);

int N;
string arr[300005];
pair<int, int> val[300005];

pair<int, int> solve(int r){
	int mxx = 1000000, mnx = 0, mxy = 1000000, mny = 0, mxd = 1000000, mnd = -1000000;	
	for(int i = 1; i<=N; i++){
		mxx = min(mxx, val[i].first + r);
		mnx = max(mnx, val[i].first - r);
		mxy = min(mxy, val[i].second + r);
		mny = max(mny, val[i].second - r);
		mxd = min(mxd, val[i].second - val[i].first + r);
		mnd = max(mnd, val[i].second - val[i].first - r);		
	}
	/*
	if(r == 11 || r == 12){
		cout << "N: " << mnx << " " << mxx << "\n";
		cout << "B: " << mny << " " << mxy << "\n";
		cout << "D: " << mnd << " " << mxd << "\n";
	}
	*/
	auto func = [&] (int x, int y){
		bool ret = x+y>0;
		ret &= (x >= mnx && x <= mxx);
		ret &= (y >= mny && y <= mxy);
		ret &= (x + mxd >= y);
		ret &= (x + mnd <= y);
		return ret;
	};
	test(mnx, mny);
	test(mnx, mxy);
	test(mxx, mny);
	test(mxx, mxy);
	test(mnx, mnx+mnd);
	test(mnx, mnx+mxd);
	test(mxx, mxx+mnd);
	test(mxx, mxx+mxd);
	test(mny-mnd, mny);
	test(mny-mxd, mny);
	test(mxy-mnd, mxy);
	test(mxy-mxd, mxy);
	/*
	if(r == 12){
		cout << func(mnx, mxy) << "\n";
	}
	*/
	return {-1, -1};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	//pair<int, int> P = {1000000, 1000000};
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		for(char c : arr[i]){
			val[i].first += (c == 'N');
			val[i].second += (c == 'B');
		}
		//P.first = min(P.first, val[i].first);
		//P.second = min(P.second, val[i].second);
		//cout << val[i].first << " " << val[i].second << "\n";
	}
	int l = 0, r = 1000000, ans = 0;
	pair<int, int> p = {0, 0};
	while(l <= r){
		int mid = l+r>>1;
		auto q = solve(mid);
		if(q.first == -1){
			l = mid + 1;
		}
		else{
			ans = mid;
			p = q;
			r = mid - 1;
		}
	}
	solve(12);
	cout << ans << "\n";
	for(int i = 1; i<=p.first; i++){
		cout << 'N';
	}
	for(int j = 1; j<=p.second; j++){
		cout << 'B';
	}
	/*
	int l = 0, r = min(P.first, P.second), ans = 0;
	while(l <= r){
		int mid = l+r>>1;
		pair<int, int> C = {P.first+mid, P.second+mid};
		bool b = 1;
		for(int i = 1; i<=N; i++){
			int radius = 0;
			if((C.first > val[i].first) == (C.second > val[i].second)){
				radius = max(abs(C.first-val[i].first), abs(C.second-val[i].second));
			}
			else{
				radius = abs(C.first-val[i].first) + abs(C.second-val[i].second);
			}
			cout << radius << " " << mid << "\n";
			if(radius > mid){
				b = 0;
			}
		}
		if(b){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans << "\n";
	for(int i= 1; i<=P.first+ans; i++){
		cout << 'N';
	}
	for(int i = 1; i<=P.second+ans; i++){
		cout << 'B';
	}
	*/
	/*
	int lx = 0, rx = (1<<20)-1, ly = 0, ry = (1<<20)-1, ans = 1000000;
	pair<int, int> P = {0, 0};
	while(lx+1 < rx || ly+1 < ry){
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;
		int midx = lx+rx>>1;
		int midy = ly+ry>>1;
		int crnt = solve(midx, midy);
		int crntup = solve(midx, midy+1);
		int crntright = solve(midx+1, midy);
		if(crnt > crntup){
			ly = midy;
		}
		else if(crnt < crntup){
			ry = midy;
		}
		else{
			
		}
		if(crnt > crntright){
			lx = midx;
		}
		else if(crnt < crntright){
			rx = midx;
		}
		else{
			
		}
	}
	for(int dx = -3; dx<=3; dx++){
		for(int dy = -3; dy<=3; dy++){
			int v = solve(lx+dx, ly+dy);
			if(ans >= solve(lx+dx, ly+dy)){
				ans = v;
				P = make_pair(lx+dx, ly+dy);
			}
		}
	}
	cout << P.first << " " << P.second << "\n";
	cout << lx << " " << ly << "\n";
	cout << ans << "\n";
	for(int i = 1; i<=P.first; i++){
		//cout << 'N';
	}
	for(int i = 1; i<=P.second; i++){
		//cout << 'B';
	}
	cout << "\n";
	for(int i = 0; i<=30; i++){
		for(int j = 0; j<=30; j++){
			cout << solve(i, j) << " ";
		}
		cout << "\n";
	}
	*/
	
}