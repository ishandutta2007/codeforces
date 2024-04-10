// Zende bad Shoma nasime faghat !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const int Sq = 333;
const int Block = 1010;
const int MX = 335;
const int Bs = 101;

int L[N], R[N], T[N];
int p[N], t[N], a[N];
int n, k, q;

typedef pair<int, pair<int, int> > Query;

vector<Query> Q;

int fl[Block], cnto[Block], cntc[Block];
ll ho[Block][MX];
ll hc[Block][MX];

ll pw[N];

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

vector<pii> I;

void Relax(){
	vector<int> V;
	for(int i = 0; i < n; i += Sq) V.pb(i);
	V.pb(0); V.pb(n);
	for(auto &X : Q){
		if(X.F == 1){
			V.pb(X.S.F - 1);
			V.pb(X.S.F);
		} else {
			V.pb(X.S.F - 1);
			V.pb(X.S.S);
		}
	}
	sort(all(V)); V.resize(unique(all(V)) - V.begin());
	int m = V.size() - 1;
	//debug("Relax");
	assert(m < Block);
	// Build
	vector<int> st;
	for(int i = 0; i < m; i++){
		fl[i] = false;
		st.clear();
		for(int j = V[i]; j < V[i + 1]; j++){
			if(a[j] < 0){
				if((st.empty()) || (st.back() < 0)) st.pb(a[j]);
				else {
					if(st.back() != -a[j]) fl[i] = true;
					else st.pop_back();
				}
			} else {
				st.pb(a[j]);
			}
		}
		if(fl[i]) continue;
		int co = 0, cc = 0;
		for(auto &x : st){
			if(x > 0) co ++;
			else cc++;
		}
		cnto[i] = co;
		cntc[i] = cc;
		ll *O = ho[i];
		ll *C = hc[i];

		for(int i = 1; i <= cc; i++) C[i] = (1ll * Bs * C[i - 1] + abs(st[i - 1]) ) % Mod;
		for(int i = 1; i <= co; i++) O[i] = (1ll * Bs * O[i - 1] + abs(st[st.size() - i]) ) % Mod;
		
	}
	int t, idx, val, l, r, del;
	for(auto &X : Q){
		t = X.F;
		//cerr << t << '\n';
		if(t == 1){
			idx = X.S.F - 1; val = X.S.S;
			a[idx] = val;
			int bl = lower_bound(all(V), idx) - V.begin();
			if(val > 0){
				cnto[bl] = 1; cntc[bl] = 0;
				ho[bl][1] = val;
			}
			if(val < 0){
				cntc[bl] = 1; cnto[bl] = 0;
				hc[bl][1] = abs(val);
			}
			continue;
		}
		l = X.S.F - 1; r = X.S.S;
		l = lower_bound(all(V), l) - V.begin();
		r = lower_bound(all(V), r) - V.begin();
	
		//debug("Fuck");
		I.clear();
		int flg = true;
		//cerr << "S\n";
		for(int i = l; i < r; i++){
			if(fl[i]){
				flg = false;
				break;
			}
			int po = 0, rq = cntc[i], po2;
			while((rq > po) && (!I.empty())){
				del = min(rq - po, I.back().S);
				po2 = cnto[I.back().F] - I.back().S;

				ll Ho = ho[I.back().F][po2 + del] - mul(ho[I.back().F][po2], pw[del]) + Mod;
				ll Hc = hc[i][po + del] - mul(hc[i][po], pw[del]) + Mod;
				Ho %= Mod;
				Hc %= Mod;
				if(Ho != Hc){
					flg = false;
					break;
				}
				po += del;
				I[I.size() - 1].S -= del;
				if(I.back().S == 0) I.pop_back();
			}
			if(po < rq) flg = false;
			if(!flg) break;
			I.pb({i, cnto[i]});
		}
		while((!I.empty()) && (I.back().S == 0)) I.pop_back();
		if(!I.empty()) flg = false;

		cout << (flg ? "Yes\n" : "No\n");
	}
	//
	Q.clear();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], Bs);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int q;
	cin >> q;
	int a, b, c;
	for(int i = 1; i <= q; i++){
		cin >> a >> b >> c;
		Q.pb({a, {b, c}});

		if(i % Sq == 0)
			Relax();
	}
	Relax();
	return 0;
}