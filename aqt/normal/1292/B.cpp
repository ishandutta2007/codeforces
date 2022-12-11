
// Problem : B. Aroma's Search
// Contest : Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

unsigned long long x, y, ax, ay, bx, by, sx, sy, t;
vector<pair<unsigned long long, unsigned long long>> v;

unsigned long long dif(unsigned long long n, unsigned long long m){
	if(n < m){
		return m - n;
	}
	else{
		return n - m;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y >> ax >> ay >> bx >> by >> sx >> sy >> t;
	do{
		v.push_back({x, y});
		x *= ax, y *= ay;
		x += bx, y += by;
	}
	while(x <= 100000000000000000LL && y <= 100000000000000000LL);
	int ans = 0;
	int idx1 = 0;
	for(auto k1 : v){
		idx1++;
		int idx2 = 0;
		for(auto k2 : v){
			idx2++;
			auto p = k1, q = k2;
			unsigned long long c = 0;
			c = dif(q.first, p.first) + dif(q.second, p.second);
			unsigned long long opt1 = 0, opt2 = 0;
			opt1 += dif(p.first, sx);
			opt1 += dif(p.second, sy);
			opt2 += dif(q.first, sx);
			opt2 += dif(q.second, sy);
			//cout << p.first << " " << p.second << " " << q.first << " " << q.second << endl;
			//cout << idx1 << " " << idx2 << endl;
			//cout << opt1 << " " << opt2 << endl;
			//cout << min(opt1, opt2)+c << endl;
			if(min(opt1, opt2)+c <= t){
				ans = max(ans, (int) (abs(idx1-idx2)+1));
			}
		}
	}
	cout << ans << endl;
}