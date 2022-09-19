// Null
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

const ll Mod = 1000000007LL;
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;
ll b[N], a[N];
ll cnt[N], mk[N], mk2[N];

vector<ll> O[N];

set<pll> st;

void Main(){
	ll x, y;
	cin >> n >> x >> y;
	
	fill(mk, mk + n + 2, 0);
	fill(mk2, mk2 + n + 2, 0);
	
	fill(cnt, cnt + n + 2, 0);
	
	st.clear();
	while(!st.empty()) st.erase(st.begin());
	for(int i = 0; i <= n + 1; i++) O[i].clear();

	for(int i = 0; i < n; i++){
		cin >> b[i];
		cnt[b[i]] ++;
		O[b[i]].pb(i);
	}
	ll ch = -1;
	for(int i = 1; i <= n + 1; i++) if(cnt[i] == 0) ch = i;
	for(int i = 1; i <= n + 1; i++) st.insert({cnt[i], i});



	ll mx, idx;
	for(int i = 0; i < x; i++){
		mx = st.rbegin() -> S;
	//	debug(mx);
		idx = O[mx].back();
	//	debug(idx);
		O[mx].pop_back();
		mk[idx] = 1;
		a[idx] = mx;
		st.erase({cnt[mx], mx});
		cnt[mx] --;
		st.insert({cnt[mx], mx});
	//	debug(cnt[mx]);
	}
	ll rq = n - y;
	//debug(rq);
	ll jmp = st.rbegin() -> S;
	//debug(rq);
	if(cnt[jmp] + cnt[jmp] - rq > n - x){
		cout << "NO\n";
	//	cout << flush;
		return ;
	}
	jmp = cnt[jmp];
	//debug(jmp);
	while(rq){
		mx = st.rbegin() -> S;
		st.erase({cnt[mx], mx});
		ll d = min(rq, cnt[mx]);
		rq -= d;
		cnt[mx] -= d;
		for(int i = 0; i < d; i++){
			idx = O[mx].back(); O[mx].pop_back();

			mk2[idx] = 1;
		}
	}

	vector<ll> I;
	for(int i = 0; i < n; i++) if(!mk[i]) I.pb(i);
	sort(all(I), [&](int i, int j){
		if(b[i] == b[j]) return i < j;
		return b[i] > b[j];
	});


	
	for(int i = 0; i < I.size(); i++){
		idx = (i + jmp + ((int)I.size()) + ((int)I.size())) % (I.size());
		a[I[idx]] = b[I[i]];
		if(mk2[I[i]]) a[I[idx]] = ch;
	}

	cout << "YES\n";
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << '\n';
	//cout << flush;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --){
		Main();
		//cout << endl;
	}
	return 0;
}
/*
1
5 2 4
3 1 1 2 5

*/