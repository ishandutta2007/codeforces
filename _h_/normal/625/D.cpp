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
#include <cstring>
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
const ll md = 1e9+7;
const ld eps = 1e-14;
const double pi = acos(-1);
const ll rnd = 54321;
const int mx = 1e5+5;

bool sub(vi &n, int ix){
	while(n[ix] == 0){
		if(ix == 0) return 0;
		n[ix] = 9;
		--ix;
	}
	--n[ix];
	return 1;
}

bool fail(string nn, int s){
	int ett = nn.size() - s;
	if(s == 0) return 1;
	int sz = nn.size();
	vi a(s), n(sz);
	rep(i,0,sz) n[i] = nn[i]-'0';
	rep(i,0,(s+1)/2){
		int j = s-i-1;
		if(i == j){
			if(n[i+ett]%2 != 0) return 1;
			a[i] = n[i+ett]/2 + (n[i+ett-1]==1?5:0);
			n[i+ett] = 0;
			n[i+ett-1] -= n[i+ett-1]==1;
		} else {
			int su = n[ett+j] + (n[ett+j]<9 && n[ett-1+i]==1 ? 10 : 0);
			/*cout << ":"<<su << endl;
			for(int x : n) cout << x;
				puts("");*/
			rep(_,0,su%10) if(!sub(n,i+ett)) return 1;
			rep(_,0,su%10) if(!sub(n,j+ett)) return 1;
			if(su >= 10 && !sub(n,i+ett-1)) return 1;
			if(su >= 10 && !sub(n,j+ett-1)) return 1;
			a[i] = min(9, su);
			a[j] = su-a[i];
		}
	}
	for(int x : n) if(x != 0 || a[0] == 0)
		return 1;
	for(int x : a) cout << x;
	cout << endl;
	return 0;
}

int main(){
	string n;
	cin >> n;
	n = "0" + n;
	if(fail(n,n.size()-1) && fail(n,n.size()-2))
		cout << 0 << endl;
}