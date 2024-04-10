
// Problem : E. Covered Points
// Contest : Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1036/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

/*
Kactl's Library
*/


template <class T> int sgn(T x){
	return (x > 0) - (x < 0);
}

template <class T> struct Point{
	typedef Point P;
	T x, y;
	explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
	bool operator < (P p) const{
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
	bool operator == (P p) const{
		return make_pair(x, y) == make_pair(p.x, p.y);
	}
	Point operator + (P p) const {
		return P(x + p.x, y + p.y);
	}
	Point operator - (P p) const {
		return P(x - p.x, y - p.y);
	}
	Point operator * (T d) const {
		return P(x * d, y * d);
	}
	Point operator / (T d) const {
		return P(x / d, y / d);
	}
	Point operator % (T d) const {
		return P(x % d, y % d);
	}
	T dot (P p) const {
		return x * p.x + y * p.y;
	}
	T cross (P p) const {
		return x * p.y - y * p.x;
	}
	T cross (P a, P b) const {
		return (a - *this).cross(b - *this);
	}
};

template<class P> bool chk(P s, P e, P p){
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> P seginter(P f1, P f2, P s1, P s2){
	auto of1 = s1.cross(s2, f1);
	auto of2 = s1.cross(s2, f2);
	auto os1 = f1.cross(f2, s1);
	auto os2 = f1.cross(f2, s2);
	if(sgn(of1) * sgn(of2) < 0 && sgn(os1) * sgn(os2) < 0){
		if((f1 * of2 - f2 * of1) % (of2 - of1) == P(0, 0)){
			return (f1 * of2 - f2 * of1) / (of2 - of1);
		}
		return P(INT_MAX, INT_MAX);
	}
	if(chk(s1, s2, f1)){
		return f1;
	}
	if(chk(s1, s2, f2)){
		return f2;
	}
	if(chk(f1, f2, s1)){
		return s1;
	}
	if(chk(f1, f2, s2)){
		return s2;
	}
	return P(INT_MAX, INT_MAX);
}

int N;
Point<long long> a[1005], b[1005];
set<Point<long long>> glst;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		set<Point<long long>> lcst;
		ans += 1 + abs(__gcd(a[i].x-b[i].x, a[i].y - b[i].y));
		for(int j = 1; j<=N; j++){
			if(i == j){
				continue;
			}
			auto p = seginter(a[i], b[i], a[j], b[j]);
			if(p.x != INT_MAX){
				lcst.insert(p);
			}
		}
		ans -= lcst.size();
		for(auto p : lcst){
			glst.insert(p);
		}
	}
	cout << ans + glst.size();
}

/*
int N;
pair<long long, long long> a[1005], b[1005], d[1005];
set<pair<long long, long long>> glst;

bool chk(long long p, long long q, long long t){
	return min(p, q) <= t && max(p, q) >= t;
}
*/

/*
pair<long long, long long> solve(int i, int j){
	long long dx = a[i].first - a[j].first;
	long long dy = a[i].second - a[j].second;
	long long lcm = 1LL * d[j].first * d[j].second / __gcd(abs(d[j].first), abs(d[j].second));
	//cout << d[j].first << " " << d[j].second << " " << lcm << "\n";
	long long dxi = d[i].first * (!d[j].second ? 0 : lcm / d[j].second);
	long long dyi = d[i].second * (!d[j].first ? 0 : lcm / d[j].first);
	dx *= (!d[j].second ? 0 : lcm / d[j].second);
	dy *= (!d[j].first ? 0 : lcm / d[j].first);
	long long c = dx - dy;
	long long coe = dyi - dxi;
	cout << coe << "\n";
	if(!coe){
		return make_pair(INT_MAX, INT_MAX);
	}
	if(d[i].first * c % coe || d[i].second * c % coe){
		return make_pair(INT_MAX, INT_MAX);
	}
	long long x = a[i].first + d[i].first * c / coe;
	long long y = a[i].second + d[i].second * c / coe;
	bool good = 1;
	cout << i << " " << j << " " << x << " " << y << "\n";
	good &= chk(a[i].first, b[i].first, x);
	good &= chk(a[j].first, b[j].first, x);
	good &= chk(a[i].second, b[i].second, y);
	good &= chk(a[j].second, b[j].second, y);
	if(good){
		return make_pair(x, y);
	}	
	return make_pair(INT_MAX, INT_MAX);
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
		d[i].first = a[i].first - b[i].first;
		d[i].second = a[i].second - b[i].second;
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		ans += 1 + abs(__gcd(d[i].first, d[i].second));
		set<pair<long long, long long>> lcst;
		for(int j = 1; j<=N; j++){
			if(i == j){
				continue;
			}
			
			cout << "doing: " << i << " " << j << "\n";
			auto p = solve(i, j);
			if(p.first == INT_MAX){
				p = solve(j, i);
				if(p.first == INT_MAX){
					continue;
				}
			}
			cout << "hi\n";
			
			lcst.insert(p);
		}
		ans -= lcst.size();
		cout << lcst.size() << "\n";
		for(auto p : lcst){
			glst.insert(p);
		}
	}
	cout << ans + glst.size();
}
*/