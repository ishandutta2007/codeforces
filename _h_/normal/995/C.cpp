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
typedef complex<ll> P;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}

	vector<P> ps(n);

	rep(i,0,n){
		int x,y;
		cin >> x >> y;
		ps[i] = P(x,y);
	}

	vi pek(n, -1), diff(n, 0);
	vector<bool> alive(n, true);

	vi ls;
	int left = n;
	rep(i,0,n) ls.push_back(i);

	while(left > 2){
		if(sz(ls) >= 1.3*left){
			vi nxt;
			trav(i, ls) if(alive[i]) nxt.push_back(i);
			ls = nxt;
			assert(sz(ls) == left);
		}

		int i,j;
		draw:
		i = rand() % sz(ls);
		j = rand() % sz(ls);
		i = ls[i], j = ls[j];

		if(!alive[i] || !alive[j] || i==j) goto draw;

		P p = ps[i]+ps[j];
		ll l = (p*conj(p)).real();
		if(l <= 1e12){
			pek[j] = i;
			diff[j] = 1;
			ps[i] = p;
			alive[j] = false;
			--left;
			continue;
		}
		p = ps[i]-ps[j];
		l = (p*conj(p)).real();
		if(l <= 1e12){
			pek[j] = i;
			diff[j] = -1;
			ps[i] = p;
			alive[j] = false;
			--left;
			continue;
		}
		goto draw;
	}

	vi nxt;
	trav(i, ls) if(alive[i]) nxt.push_back(i);

	int i = nxt[0], j = nxt[1];
	P p = ps[i] + ps[j];
	if( (p*conj(p)).real() <= 2e12 ){
		diff[j] = 1;
	} else {
		diff[j] = -1;
	}
	pek[j] = i;
	alive[j] = false;

	vi ans(n);
	vector<vi> ch(n);
	rep(k,0,n) if(k != i) ch[pek[k]].push_back(k);

	stack<int> st;
	st.push(i);
	ans[i] = 1;
	while(!st.empty()){
		int v = st.top();
		st.pop();
		trav(u, ch[v]){
			ans[u] = ans[v] * diff[u];
			st.push(u);
		}
	}
	rep(i,0,n) cout << ans[i] << ' ';
	cout << endl;

}