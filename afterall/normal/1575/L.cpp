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

int fen[N];
void Add(int idx, int x){
	idx ++;
	for(; idx < N; idx += (idx & (-idx)))
		fen[idx] = max(fen[idx], x);
}
int Get(int idx){
	int res = -N;
	idx ++;
	for(; idx; idx -= (idx & (-idx)))
		res = max(fen[idx], res);
	return res;
}

vector<int> V[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		V[v].pb(i);
	}
	fill(fen, fen + N, -N);
	Add(0, 0);
	int ans = 0;
	for(int i = 1; i < N; i++){
		reverse(all(V[i]));
		for(auto idx : V[i]){
			if(idx < i) continue;
			int res = Get(idx - i) + 1;
			ans = max(ans, res);
			Add(idx - i, res);
		}
	}
	cout << ans << '\n';
	return 0;
}