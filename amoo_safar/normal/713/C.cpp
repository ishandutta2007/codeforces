// har ki ro didi goft mikhad beshe meslemon !
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

priority_queue<int> pq;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// pq.push(1);
	// pq.push(2);
	// cout << pq.top() << '\n';
	int n;
	cin >> n;
	ll v;
	ll h = 0;
	pq.push(0);
	for(int i = 0; i < n; i++){
		cin >> v;
		v -= i;
		v += n;
		// cerr << "! " << v << '\n';
		h += v;
		pq.push(v);
		pq.push(v);
		pq.pop();
		// debug(pq.size());
	}
	// debug(pq.size());
	ll m = -n;

	vector<ll> V;
	while(!pq.empty()){
		V.pb(pq.top());
		pq.pop();
	}
	// debug(h);
	reverse(all(V));
	for(int i = 0; i + 1 < (int) V.size(); i++){
		h += (V[i + 1] - V[i]) * m;
		// debug(h);
		m ++;
	}
	// debug(m);
	cout << h << '\n';
	return 0;
}