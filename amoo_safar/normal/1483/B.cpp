// vaziat meshki-ghermeze !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N];


set<int> pos;
int nxt(set<int>::iterator it){
	if(next(it) == pos.end())
		return *pos.begin();
	return *next(it);
}
int prv(set<int>::iterator it){
	if(it == pos.begin())
		return *pos.rbegin();
	return *prev(it);
}

int Main(){
	pos.clear();
	int n;
	cin >> n;
	set<int> bad;
	for(int i = 1; i <= n; i++) pos.insert(i);
	for(int i = 1; i <= n; i++) cin >> a[i];
	set<int>::iterator it = pos.begin();
	for(int i = 1; i <= n; i++){
		if(__gcd(a[*it], a[nxt(it)]) == 1){
			bad.insert(*it);
			// debug(*it);
		}
		if(i != n)
			it ++;
	}
	// debug("YY");
	int nw = 1;
	vector<int> ans;
	while(!bad.empty()){
		auto lb = bad.lower_bound(nw);
		int wh = -1;
		if(lb == bad.end()) wh = *bad.begin();
		else wh = *lb;
		// debug(wh);
		int dl = nxt(pos.find(wh));
		// debug(dl);
		bad.erase(wh);
		bad.erase(dl);
		pos.erase(dl);

		ans.pb(dl);
		nw = dl;
		if(pos.empty()) break;
		if(__gcd(a[wh], a[nxt(pos.find(wh))]) == 1)
			bad.insert(wh);
	}
	cout << ans.size();
	for(auto x : ans) cout << ' ' << x;
	cout << '\n';

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();

	return 0;
}
/*
1
2
1 2

*/