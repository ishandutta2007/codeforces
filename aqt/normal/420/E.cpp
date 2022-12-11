
// Problem : E. Playing the ball
// Contest : Codeforces - Coder-Strike 2014 - Finals (online edition, Div. 1)
// URL : https://codeforces.com/contest/420/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct event{
	double x, y;
	int idx;
	bool typ;
	double ang;
	bool operator < (const event e) const {
		if(abs(ang - e.ang) < EPS){
			return typ > e.typ;
		}
		return ang < e.ang;
	}
};

int N, D, M = 15000, T;
int x[20005], y[20005], r[20005];
int fre[20005];
set<int> st;
vector<event> v;

void add(double r, double a, double b, double c){
	double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+EPS);
	else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
		v.push_back({x0, y0, ++T, 1, atan2(y0, x0)});
		v.push_back({x0, y0, T, 0, atan2(y0, x0)});
	}
	else {
	    double d = r*r - c*c/(a*a+b*b);
	    double mult = sqrt (d / (a*a+b*b));
	    double ax, ay, bx, by;
	    ax = x0 + b * mult;
	    bx = x0 - b * mult;
	    ay = y0 - a * mult;
	    by = y0 + a * mult;
	    //cout << atan2(ay, ax) << " " << atan2(bx, by) << "\n";
	    v.push_back({ax, ay, ++T, 0, atan2(ay, ax)}); //order might not be good
	    v.push_back({bx, by, T, 1, atan2(by, bx)});
	}
}

int upd(event e){
	if(e.typ == 1){
		st.insert(e.idx);
		return 1;
	}
	else{
		if(st.count(e.idx)){
			st.erase(e.idx);
			return -1;
		}
		return 0;
	}	
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> D;
	for(int i = 1; i<=N; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	for(int R = D; R<=M; R+=D){
		for(int n = 1; n<=N; n++){
			int A = -2*x[n];
			int B = -2*y[n];
			int C = x[n]*x[n]+y[n]*y[n]+R*R-r[n]*r[n];
			add(R, A, B, C);
		}
	}
	sort(v.begin(), v.end());
	int ans = 0, cnt = 0;
	for(event e : v){
		//cout << e.x << " " << e.y << " " << e.typ << "\n";
		cnt += upd(e);
	}
	ans = cnt;
	//cout << cnt << "\n";
	for(int i = 0; i<v.size(); ){
		double ang = v[i].ang;
		while(i < v.size() && abs(ang-v[i].ang) < EPS && v[i].typ == 1){
			cnt += upd(v[i++]);
		}
		ans = max(ans, cnt);
		while(i < v.size() && abs(ang-v[i].ang) < EPS && v[i].typ == 0){
			cnt += upd(v[i++]);
		}
	}
	cout << ans << "\n";
}