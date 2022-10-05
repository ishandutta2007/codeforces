#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

double a, b, c, x1, y1, x2, y2, ans;
double sqr(double x){
	return x * x;
}
double dist(double x1, double y1, double x2, double y2){
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}                               
pair< double , double > getx(double x){
	return {x, -(a * x + c) / b}; 
}

pair< double , double > gety(double y){
	return {-(b * y + c) / a, y}; 
}

int main(){
	cin >> a >> b >> c;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	ans = abs(x1 - x2) + abs(y1 - y2);
	vector< pair< double, double> > v1, v2;
	v1.pb(getx(x1));
    v1.pb(gety(y1));

    v2.pb(getx(x2));
    v2.pb(gety(y2));
    for(auto i : v1)
    	for(auto j : v2){
			ans = min(ans, dist(x1, y1, i.f, i.s) +  dist(j.f, j.s, i.f, i.s) + dist(x2, y2, j.f, j.s));
			//cerr << dist(x1, y1, i.f, i.s) +  dist(j.f, j.s, i.f, i.s) + dist(x2, y2, j.f, j.s) << endl;
		}
	cout << fixed << setprecision(20) << ans;
	return 0;
}