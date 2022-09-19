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
ll dis(ll i, ll j){
	return (A[i].F - A[j].F)*(A[i].F - A[j].F) + (A[i].S - A[j].S)*(A[i].S - A[j].S);
}
ll mk[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	pll mn = {Inf, Inf};
	ll idx = -1;
	for(int i = 1; i <= n; i++){
		cin >> A[i].F >> A[i].S;
		if(A[i] < mn){
			mn = A[i];
			idx = i;
		}
	}
	cout << idx << ' ';
	mk[idx] = 1;
	for(int i = 2; i <= n; i++){
		ll mx = -1;
		ll id = -1;
		for(int j = 1; j <= n; j++){
			if(mk[j]) continue;
			if(mx < dis(idx, j)){
				mx = dis(idx, j);
				id = j;
			}
		}
		idx = id;
		mk[id] = 1;
		cout << idx << ' ';
	}
	cout << '\n';
	return 0;
}