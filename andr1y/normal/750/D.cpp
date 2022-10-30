#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 31
#define INF 101111111111111
using namespace std;
ll a[N];
bool was[350][350];
bool pos[350][350][N][8];
const int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
queue<pair<pll, pll>> q;
int main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> a[i];
    pos[150][150][1][0] = 0;
	q.push({{150, 150}, {1, 0}});
	while(!q.empty()){
		pair<pll, pll> now = q.front(); q.pop();
		ll nx = now.x.x, ny = now.x.y, type = now.y.x, nap = now.y.y;
		for(ll i = 1;i<=a[type];i++){
			nx += dir[nap][0];
			ny += dir[nap][1];
			was[nx][ny] = 1;
		}
		ll l = (nap+7)&7, r = (nap+1)&7;
		if(type == n) continue;
		if(!pos[nx][ny][type+1][l]){
			pos[nx][ny][type+1][l] = 1;
			q.push({{nx, ny}, {type+1, l}});
		}
		if(!pos[nx][ny][type+1][r]){
			pos[nx][ny][type+1][r] = 1;
			q.push({{nx, ny}, {type+1, r}});
		}
	}
	ll res =0;
	for(ll i =0;i<350;i++){
		for(ll j = 0;j<350;j++) res += (was[i][j] ? 1 : 0);
	}
	cout << res;
}