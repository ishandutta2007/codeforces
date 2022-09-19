// Doooop !
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

int mk[N];

int Main(){
	int n, k;
	cin >> n >> k;
	fill(mk, mk + n + n + 3, 0);
	vector<pll> V;
	int x, y;
	for(int i = 0; i < k; i++){
		cin >> x >> y;
		if(x > y) swap(x, y);
		V.pb({x, y});
		mk[x] = mk[y] = 1;
	}
	vector<int> P;
	for(int i = 1; i <= n + n; i++) if(!mk[i]) P.pb(i);
	int d = P.size() / 2;
	for(int i = 0; i < d; i++)
		V.pb({P[i], P[i + d]});
	sort(all(V));
	int ans = 0;
	for(int i = 0; i < (int) V.size(); i++)
		for(int j = i + 1; j < (int) V.size(); j++)
			if(V[j].F <= V[i].S && V[i].S <= V[j].S)
				ans ++;
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}