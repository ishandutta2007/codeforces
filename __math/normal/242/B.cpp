#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

struct P{
	int x,y;
	bool operator <(const P& l) const{
		if(x != l.x) return x < l.x;
		return y > l.y;
	}

	bool operator ==(const P& l) const{
		return x == l.x && y == l.y;
	}
};

int get_id(vector<P> &v){
	vector<P> vs(v);
	sort(vs.begin(),vs.end());
	P& st = vs[0];
	return find(v.begin(),v.end(),st) - v.begin();
}

int main(){
	int n; cin>>n;
	vector<P> v(n); FOR(i,n) cin>>v[i].x >> v[i].y;

	int id = get_id(v);

	bool ok = true;
	FOR(i,sz(v)){
		if(v[id].x <= v[i].x && v[i].y <= v[id].y)
			continue;
		ok = false;
		break;
	}

	if(!ok){
		puts("-1");
		return 0;
	}else{
		cout << id+1 << endl;
	}

	return 0;
}