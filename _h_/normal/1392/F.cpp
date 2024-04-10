#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<ll> vl;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vl h(n);
	trav(x, h) cin >> x;

	int m = n-1;
	vl d(m+1);
	rep(i,0,m) d[i] = h[i+1] - h[i];

	stack<int> tom;
	rep(i,0,m){
		while(d[i] >= 2){
			int l = tom.empty() ? -1 : tom.top();
			if(d[i] >= 1 + i-l){
				if(tom.empty()){
					ll k = d[i] / (1 + i-l);
					d[i] -= k * (1 + i-l);
					d[i+1] += k * (i-l);
				} else {
					d[i] -= 1 + i-l;
					d[i+1] += i-l;
					d[l] = 1;
					tom.pop();
				}
			} else {
				int r = l + d[i]-1;
				d[i+1] += d[i]-1;
				d[i] = 1;
				if(l >= 0){
					d[l] = 1;
					tom.pop();
				}
				d[r] = 0;
				tom.push(r);
			}
		}
		if(d[i] == 0) tom.push(i);
	}
	vl ans(n);
	rep(i,0,m) ans[i+1] = ans[i] + d[i];
	ll sum = 0, gol = 0;
	trav(x, h) gol += x;
	trav(x, ans) sum += x;
	ll dif = (gol - sum) / n;
	trav(x, ans) cout << x+dif << " ";
	cout << endl;
}