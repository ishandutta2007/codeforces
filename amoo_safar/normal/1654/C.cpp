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

const int Mod = 1000000007LL;
const int N = 3e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int A[N];

int Main(){
	int n;
	cin >> n;
	ll sm = 0;
	map<ll, int> mp;
	int v;
	for(int i = 0; i < n; i++){
		cin >> v;
		sm += v;
		mp[v] ++;
	}
	multiset<ll> pc; pc.insert(sm);
	int mt = 0, ct = 0;
	while(!pc.empty() && ct <= n){
		ll bk = *pc.rbegin(); pc.erase(--pc.end());
		if(mp[bk] > 0){
			mp[bk] --;
			mt ++;
		} else {
			if(bk == 1) return cout << "NO\n", 0;
			pc.insert(bk / 2);
			pc.insert((bk + 1) / 2);
			ct ++;
		}
	}
	cout << (mt == n ? "YES\n" : "NO\n");
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}