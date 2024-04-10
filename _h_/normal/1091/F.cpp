#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll inf = 1e18;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> ls(n);
	string s;
	trav(x, ls) cin >> x;
	cin >> s;

	vector<ll> gsuf(n+1), wsuf(n+1), lsuf(n+1);
	rrep(i,0,n){
		gsuf[i] = gsuf[i+1];
		wsuf[i] = wsuf[i+1];
		lsuf[i] = lsuf[i+1];
		if(s[i]=='G') gsuf[i] += ls[i];
		if(s[i]=='W') wsuf[i] += ls[i];
		if(s[i]=='L') lsuf[i] += ls[i];
	}

	vector<ll> wgl(n+1);
	rep(i,0,n) wgl[i] = -gsuf[i] - lsuf[i] + wsuf[i];
	vector<ll> wglmax(n+1);
	rrep(i,0,n) wglmax[i] = max(wgl[i], wglmax[i+1]);

	auto fly = [&](int pos, ll stam){
		if(stam + wgl[pos] < wglmax[pos]) return -1LL;

		ll ans = gsuf[pos] + lsuf[pos] + 3 * wsuf[pos];
		stam += wgl[pos];
		if(pos && s[pos-1]=='G'){
			ll d = min(stam - wglmax[pos], 2 * (ls[pos-1]));
			stam -= d;
			ans -= 2 * d;
		}
		ans -= min(stam, 2*wsuf[pos]);
		return ans;
	};

	ll best = inf;

	ll stam = 0, cur = 0;
	bool seenWater = false;
	rep(i,0,n+1){
		ll res = fly(i, stam);
		if(res != -1) best = min(best, cur + res);
		if(i == n) break;
		if(s[i] == 'G'){
			stam += ls[i];
			cur += 5 * ls[i];
		} else if(s[i] == 'W'){
			seenWater = true;
			stam += ls[i];
			cur += 3 * ls[i];
		} else {
			stam -= ls[i];
			cur += ls[i];
			if(stam < 0){
				ll cost = seenWater ? 3 : 5;
				cur += cost * (-stam);
				stam = 0;
			}
		}
	}
	cout << best << endl;
}