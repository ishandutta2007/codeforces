#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll inf = 1LL<<60;
const ld eps = 1e-14;

double x,y,vx,vy,a,b,c,d;
double l;
double hx, hy;

void ver(double di){
	x += hx*di;
	y += hy*di;
}

void hor(double di){
	x += hy*di;
	y -= hx*di;
}

void p(){
	cout << x << ' ' << y << endl;
}

int main(){
	cin>>x>>y>>vx>>vy>>a>>b>>c>>d;
	l = sqrt(vx*vx+vy*vy);
	hx = vx/l, hy = vy/l;
	cout.precision(15);
	ver(b);
	p();
	hor(-a/2);
	ver(-b);
	p();
	hor((a-c)/2);
	p();
	ver(-d);
	p();
	hor(c);
	p();
	ver(d);
	p();
	hor((a-c)/2);
	p();
}