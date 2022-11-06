//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <cassert>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second.first
#define trd second.second
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,pair<ll,ll> > Point;
typedef pair<int,int> pii;

struct Line{
	int ix;
	ll a,b,c;
};

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

Point skar(const Line &a, const Line &b){
	ll det = a.a*b.b - a.b*b.a;
	if(det == 0)
		return mp(0,mp(0,0));
	ll x = a.c*b.b - b.c*a.b;
	ll y = b.c*a.a - a.c*b.a;
	if(det < 0)
		det = -det,
		x = -x,
		y = -y;
	ll d = abs(gcd(det,gcd(x,y)));
	det /= d;
	x /= d;
	y /= d;
	return mp(det,mp(x,y));
}

bool online(const Point &p, const Line &l){
	return p.snd*l.a + p.trd*l.b == p.fst*l.c;
}

int n,k;
vector<Line> lines;
vector<pii> ans;

bool yesno(){
	if(n == 0)
		return 1;
	if(k == 0)
		return 0;
	if(n > k*k){
		rep(i,0,k*(k-1)+1){
			map<Point,int> sects;
			rep(j,0,n){
				Point x = skar(lines[i], lines[j]);
				if(x.fst != 0 && ++sects[x] >= k){
					ans.pb(pii(lines[i].ix, lines[j].ix));
					vector<Line> tmp;
					for(auto l : lines)
						if(!online(x,l))
							tmp.pb(l);
					lines = tmp;
					n = lines.size();
					--k;
					return yesno();
				}
			}
		}
		return 0;
	}
	int m = ans.size();
	Line l = lines[0];
	lines.erase(lines.begin());
	ans.pb(pii(l.ix,-1));
	int ktmp = --k;
	--n;
	vector<Line> tmp = lines;
	if(yesno())
		return 1;
	while(ans.size() > m)
		ans.pop_back();
	map<Point,int> sects;
	for(auto li : lines)
		sects[skar(l,li)] = li.ix;
	for(auto xi : sects)
		if(xi.first.fst != 0){
			ans.pb(pii(l.ix,xi.second));
			lines.resize(0);
			for(auto li : tmp)
				if(!online(xi.first,li))
					lines.pb(li);
			n = lines.size();
			k = ktmp;
			if(yesno())
				return 1;
			while(ans.size() > m)
				ans.pop_back();
		}
	return 0;
}

int main(){
	cin >> n >> k;
	lines.resize(n);
	rep(i,0,n)
		lines[i].ix = i+1,
		cin >> lines[i].a >> lines[i].b >> lines[i].c;
	if(yesno()){
		cout << "YES\n" << ans.size() << endl;
		for(auto p : ans)
			cout << p.first << ' ' << p.second << endl;
	} else {
		cout << "NO\n";
	}

}