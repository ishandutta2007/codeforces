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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N][N];
vector<ll> V[N], A[N];
int pl[N], pr[N];

int Main(){
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		ll v;
		A[i].clear();
		V[i].clear();
		for(int j = 0; j < m; j++){
			cin >> v;
			V[i].pb(v);
		}
		sort(all(V[i]));
		pl[i] = 0;
		pr[i] = m - 1;
	}
	for(int it = 0; it < m; it++){
		int idx = 0;
		for(int i = 0; i < n; i ++)
			if(V[i][pl[i]] < V[idx][pl[idx]])
				idx = i;
		// debug(idx);
		for(int i = 0; i < n; i++){
			if(i == idx){
				A[i].pb(V[i][pl[i]]);
				// cout << V[i][pl[i]] << ' ';
				pl[i] ++;
			} else {
				A[i].pb(V[i][pr[i]]);
				// cout << V[i][pr[i]] << ' ';
				pr[i] --;
			}
		}
		// cout << '\n';
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << A[i][j] << " \n"[j == m-1];
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}