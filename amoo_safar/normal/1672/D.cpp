// Son
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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N], b[N], mt[N], rq[N];

int Main(){
	vector<int> V;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	if(a[n - 1] != b[n - 1]) return cout << "NO\n", 0;

	fill(mt, mt + n + 1, -1);
	fill(rq, rq + n + 1, 0);
	b[n] = -1;
	int po = n - 1;
	int la = n - 1;
	for(int i = n - 1; i >= 0; i--){
		if(b[i] == b[i + 1]){
			rq[la] ++;
			continue;
		}
		while(po >= 0 && a[po] != b[i]) po --;
		if(po == -1) return cout << "NO\n", 0;
		mt[po] = i;
		la = po;
		po --;
	}
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		if(mt[i] != -1) {
			mp[a[i]] -= rq[i];
			if(mp[a[i]] < 0) return cout << "NO\n", 0;
		} else {
			mp[a[i]] ++;
		}
	}
	cout << "YES\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}