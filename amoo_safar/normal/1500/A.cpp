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
const int N = 3e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<int> V[N];

vector<pll> d[N];
pll mk[N];
int a[N];

void Check(int o){
	for(int fs = 0; fs < d[o].size(); fs ++)
		for(int sc = 0; sc < d[o].size(); sc ++){
			if(d[o][fs].F == d[o][sc].F) continue;
			if(d[o][fs].F == d[o][sc].S) continue;
			if(d[o][fs].S == d[o][sc].F) continue;
			if(d[o][fs].S == d[o][sc].S) continue;
			cout << "YES\n";
			cout << d[o][fs].F << ' ' << d[o][sc].S << ' ' << d[o][fs].S << ' ' << d[o][sc].F << '\n';
			exit(0);
		}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[i] = x;
		V[x].pb(i);
	}
	// 4
	vector<int> C2;
	for(int i = 1; i < N; i++){
		if(V[i].size() >= 4){
			cout << "YES\n";
			cout << V[i][0] << ' ' << V[i][1] << ' ' << V[i][2] << ' ' << V[i][3] << '\n';
			return 0;
		}
		if(V[i].size() >= 2) C2.pb(i);
	}
	// 2 - 2
	if(C2.size() >= 2){
		int f = C2[0];
		int s = C2[1];
		cout << "YES\n" << V[f][0] << ' ' << V[s][0] << ' ' << V[f][1] << ' ' << V[s][1] << '\n';
		return 0;
	}
	// 2;
	if(C2.size() == 1){
		int md = C2[0];
		for(int i = 1; i < md; i++){
			if(V[i].empty()) continue;
			int rq = md + md - i;
			if(rq < N){
				if(V[rq].size() >= 1){
					cout << "YES\n";
					cout << V[i][0] << ' ' << V[rq][0] << ' ' << V[md][0] << ' ' << V[md][1] << '\n';
					return 0;
				}
			}
		}
	}
	vector<int> I(n);
	iota(all(I), 1);
	sort(all(I), [&](int i, int j){
		return a[i] < a[j];
	});

	for(int id = 0; id < n; id ++){
		int nw = I[id];
		for(int bf : I){
			if(bf == nw) break;
			d[a[nw] - a[bf]].pb({nw, bf});
			Check(a[nw] - a[bf]);
		}
	}
	cout << "NO\n";
	return 0;
}