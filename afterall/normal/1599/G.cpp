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

pll A[N];
int n, k;

vector<int> U;
void Check(int a, int b){
	pll V = pll(A[a].F - A[b].F, A[a].S - A[b].S);
	vector<int> res = {a, b};
	for(int i = 0; i < n; i++){
		if(i == a || i == b) continue ;
		pll V2 = pll(A[a].F - A[i].F, A[a].S - A[i].S);
		if(V.F * V2.S == V.S * V2.F) res.pb(i);	
	}
	// debug(res.size());
	if(res.size() == n - 1) U = res;
}
ld dis(int i, int j){
	return sqrt((A[i].F - A[j].F) * (A[i].F - A[j].F) + (A[i].S - A[j].S) * (A[i].S - A[j].S));
}
int mk[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k; k--;
	for(int i = 0; i < n; i++)
		cin >> A[i].F >> A[i].S;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < i; j++)
			Check(i, j);
	sort(all(U), [&](int i, int j){
		return A[i] < A[j];
	});
	debug(U.size());

	for(auto c : U) mk[c] = 1;
	int nt = -1;
	for(int i = 0; i < n; i++) if(!mk[i]) nt = i;
	int idx = -1;
	for(int i = 0; i < n - 1; i++)
		if(U[i] == k) idx = i;
	
	ld al = dis(U[0], U[n - 2]);
	if(idx == -1){
		ld ans = Inf;
		for(int i = 0; i < n - 1; i++)
			ans = min(ans, al + dis(k, U[i]) + min(dis(U[0], U[i]), dis(U[i], U[n - 2]) ) );
		cout << fixed << setprecision(16) << ans << '\n';
		return 0;
	}
	ld ln = al + min(dis(U[0], k), dis(k, U[n - 2]) );
	ld ans = Inf;
	

	ans = min(ans, al + dis(k, U[0]) + dis(U[n - 2], nt));
	ans = min(ans, al + dis(k, U[n - 2]) + dis(U[0], nt));
	ans = min(ans, dis(k, nt) + al + min(dis(nt, U[0]), dis(nt, U[n-2])) );
	
	if(idx != 0){
		ans = min(ans, dis(k, U[n - 2]) + dis(U[n - 2], nt) + dis(nt, U[idx - 1]) + dis(U[idx - 1], U[0]));
		ans = min(ans, al - dis(U[idx], U[idx - 1]) + dis(U[0], nt) + dis(U[n - 2], nt));
	}

	if(idx != n - 2){
		ans = min(ans, dis(k, U[0]) + dis(U[0], nt) + dis(nt, U[idx + 1]) + dis(U[idx + 1], U[n - 2]));
		ans = min(ans, al - dis(U[idx], U[idx + 1]) + dis(U[0], nt) + dis(U[n - 2], nt));
	}

	for(int i = idx + 1; i + 1 < n - 2; i++){
		ld mn = min(dis(nt, U[i + 1]), dis(nt, U[n-2]));
		ans = min(ans, dis(U[0], k)+al-dis(U[i],U[i+1])+dis(nt, U[i]) + mn);
		ans = min(ans, dis(k, U[i])+al-dis(U[i],U[i+1])+dis(nt,U[0]) + mn);
	}
	for(int i = 1; i < idx; i++){

		ld mn = min(dis(nt, U[i - 1]), dis(nt, U[0]));

		ans = min(ans, dis(U[n - 2], k)+al-dis(U[i],U[i-1])+dis(nt, U[i]) + mn);
		
		ans = min(ans, dis(k, U[i])+al-dis(U[i],U[i-1])+dis(nt,U[n - 2]) + mn);
	}

	cout << fixed << setprecision(16) << ans << '\n';
	return 0;
}