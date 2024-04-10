// I'll Crush you !
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

vector< pair<int, str> > V;

vector<ll> G[30];
ll deg[30];
ll mk[30];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll p;
	str s;
	for(int i = 0; i < n; i++){
		cin >> p;
		for(int j = 0; j < k; j++){
			cin >> s;
			for(auto x : s) mk[x - 'a'] = 1;
			V.pb({p * k + j, s});
		}
	}
	sort(all(V));
	ll m = V.size();
	for(int i = 1; i < m; i++){
		int sz = min(V[i - 1].S.size(), V[i].S.size());
		int fl = 0;
		for(int j = 0; j < sz; j++){
			if(V[i - 1].S[j] != V[i].S[j]){
				G[V[i - 1].S[j] - 'a'].pb(V[i].S[j] - 'a');
				deg[V[i].S[j] - 'a'] ++;
				fl = 1;
				break;
			}
		}
		if(!fl && V[i - 1].S.size() > V[i].S.size())
			return cout << "IMPOSSIBLE\n", 0;
	}

	queue<ll> Q;
	str ans = "";
	for(int i = 0; i < 26; i++) if(deg[i] == 0){
		Q.push(i);
	}
	while(!Q.empty()){
		ll fr = Q.front(); Q.pop();
		ans += (char)(fr + 'a');
		for(auto adj : G[fr]){
			deg[adj] --;
			if(deg[adj] == 0){
				Q.push(adj);
			}
		}
	}
	if(ans.size() != 26)
		cout << "IMPOSSIBLE\n";
	else{
		for(auto c : ans) if(mk[c - 'a']) cout << c;
		cout << '\n';
	}
	return 0;
}