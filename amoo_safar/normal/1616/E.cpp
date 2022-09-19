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
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int n;
vector<int> V[30];
int fen[N];	
using T = int;
void Add(int idx, T x){
	for(; idx < n + 3; idx += (idx & (-idx)))
		fen[idx] += x;
}
T Get(int idx){
	T res = 0;
	for(; idx; idx -= (idx & (-idx)))
		res += fen[idx];
	return res;
}
int mk[N];
int Main(){
	for(int i = 0; i < 30; i++) V[i].clear();
	cin >> n;
	fill(fen, fen + n + 2, 0);
	fill(mk,   mk + n + 2, 0);
	
	str s, t;
	cin >> s >> t;
	for(int i = 1; i <= n; i++) Add(i, +1);
	for(int i = n; i >= 1; i--){
		V[s[i - 1] - 'a'].pb(i);
	}
	ll tmp = 0, ans = Inf;
	int po = 1;
	for(int i = 0; i < n; i++){
		while(mk[po]) po ++;
		// debug(po);
// 
		if(s[po - 1] < t[i]){
			// debug("WTF\n");
			ans = min(ans, tmp);
			break;
		}
		// calc
		for(int j = 0; j < t[i] - 'a'; j++){
			if(V[j].empty()) continue;
			ans = min(ans, tmp + Get(V[j].back() - 1));
		}
		if(V[t[i]-'a'].empty()) break;
		int wh = V[t[i]-'a'].back(); V[t[i]-'a'].pop_back();
		mk[wh] = 1;
		Add(wh, -1);
		tmp += Get(wh - 1);
	}
	// debug(ans);
	cout << (ans > 1ll * n * n ? -1 : ans) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}