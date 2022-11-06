#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll area(int i, int j, int k){
	cout << 1 << " " << i << " " << j << " " << k << endl;
	ll res;
	cin >> res;
	return res;
}

int sign(int i, int j, int k){
	cout << 2 << " " << i << " " << j << " " << k << endl;
	int res;
	cin >> res;
	return res;
}

void ans(vi &p){
	cout << 0 << endl;
	trav(x, p) cout << x << " ";
	cout << endl;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<ll> as(n+1);
	vi plus, minus;
	rep(i,3,n+1){
		as[i] = area(1,2,i);
	}
	rep(i,3,n+1){
		if(sign(1,2,i) == 1){
			plus.push_back(i);
		} else {
			minus.push_back(i);
		}
	}
	auto order = [&](vi &ls, int sig){
		if(ls.empty()) return ls;
		int mx = -1;
		trav(x, ls) if(mx == -1 || as[x] > as[mx]) mx = x;
		for(auto it = ls.begin(); it < ls.end(); ++it) if(*it == mx){
			ls.erase(it);
			break;
		}
		sort(all(ls),[&](int a, int b){
			return as[a] < as[b];
		});
		vi ll, rr;
		trav(a, ls){
			if(sign(1,mx,a) == sig) ll.push_back(a);
			else rr.push_back(a);	
		}
		vi res;
		trav(x, ll) res.push_back(x);
		res.push_back(mx);
		reverse(all(rr));
		trav(x, rr) res.push_back(x);
		return res;
	};
	vi oplus = order(plus, 1);
	vi ominus = order(minus, -1);
	reverse(all(oplus));

	vi p;
	p.push_back(1);
	trav(x, ominus) p.push_back(x);
	p.push_back(2);
	trav(x, oplus) p.push_back(x);
	ans(p);
}