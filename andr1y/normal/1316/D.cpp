#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 1488;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
vector<pll> cutpoints;
pll a[N][N];
bool lp[N][N];
bool ban[N][N];
char c[N][N];
bool e[N][N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =1;i<=n;i++){
		for(ll j =1;j<=n;j++){
			cin >> a[i][j].x >> a[i][j].y;
			if(a[i][j].x == i && a[i][j].y == j){
				cutpoints.pb({i, j});
			}
			if(a[i][j].x == -1 && a[i][j].y == -1){
				lp[i][j] = 1;
			}
		}
	}
	bool ok = 1;
	for(auto st: cutpoints){
		if(ban[st.x][st.y]){
			ok = 0;
			break;
		}
		c[st.x][st.y] = 'X';
		ban[st.x][st.y] = 1;
		queue<pll> q;
		q.push(st);
		while(!q.empty()){
			pll e = q.front();
			q.pop();
			if(e.x > 1){
				/*if(ban[e.x-1][e.y] && a[e.x-1][e.y] != st){
					ok = 0;
					break;
				}else*/ if(!ban[e.x-1][e.y] && a[e.x-1][e.y] == st){
					ban[e.x-1][e.y] = 1;
					c[e.x-1][e.y] = 'D';
					q.push({e.x-1, e.y});
				}
			}
			if(e.x+1 <= n){
				/*if(ban[e.x+1][e.y] && a[e.x+1][e.y] != st){
					ok = 0;
					break;
				}else*/ if(!ban[e.x+1][e.y] && a[e.x+1][e.y] == st){
					ban[e.x+1][e.y] = 1;
					c[e.x+1][e.y] = 'U';
					q.push({e.x+1, e.y});
				}
			}
			if(e.y > 1){
				/*if(ban[e.x][e.y-1] && a[e.x][e.y-1] != st){
					ok = 0;
					break;
				}else*/ if(!ban[e.x][e.y-1] &&  a[e.x][e.y-1] == st){
					ban[e.x][e.y-1] = 1;
					c[e.x][e.y-1] = 'R';
					q.push({e.x, e.y-1});
				}
			}
			if(e.y+1 <= n){
				/*if(ban[e.x][e.y+1] &&  a[e.x][e.y+1] != st){
					ok = 0;
					break;
				}else*/ if(!ban[e.x][e.y+1] &&  a[e.x][e.y+1] == st){
					ban[e.x][e.y+1] = 1;
					c[e.x][e.y+1] = 'L';
					q.push({e.x, e.y+1});
				}
			}
		}
		//if(!ok) break;
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = 1;j<=n;j++){
			if(!ban[i][j] && !lp[i][j]) ok = 0;
		}
	}
	if(!ok) cout << "INVALID\n";
	else{
		for(ll i = 1;i<=n;i++){
			for(ll j = 1;j<=n;j++){
				if(lp[i][j]){
					if(j > 1 && lp[i][j-1]){
						c[i][j] = 'L';
						e[i][j] = 1;
					}else{
						if(j+1 <= n && lp[i][j+1]){
							c[i][j] = 'R';
							e[i][j] = 1;
						}
					}
				}
			}
		}
		for(ll i = 1;i<=n;i++){
			for(ll j = 1;j<=n;j++){
				if(lp[i][j] && !e[i][j]){
					if(i > 1 && lp[i-1][j]){
						c[i][j] = 'U';
						e[i][j] = 1;
					}else if(i+1 <= n && lp[i+1][j]){
						c[i][j] = 'D';
						e[i][j] = 1;
					}else{
						ok = 0;
						break;
					}
				}
			}
			if(!ok) break;
		}
		if(!ok) cout << "INVALID\n";
		else{
			cout << "VALID\n";
			for(ll i = 1;i<=n;i++){
				for(ll j = 1;j<=n;j++) cout << c[i][j];
				cout << '\n';
			}
		}
	}
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}