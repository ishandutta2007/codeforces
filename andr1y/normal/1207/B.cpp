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
#define N 50
#define INF 101111111111111
using namespace std;
ll a[N][N], b[N][N];
main(){
    FAST;
    ll n, m;
    cin >> n >> m;
    vector<pll> mb;
    for(ll i = 0;i<n;i++){
    	for(ll j = 0;j<m;j++){
    		cin >> a[i][j];
    	}
    }
    for(ll i = 0;i<n-1;i++){
    	for(ll j = 0;j<m-1;j++){
    		if(a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) mb.pb({i, j});
    	}
    }
    for(auto &i : mb){
    	b[i.x][i.y] = 1;
    	b[i.x+1][i.y] = 1;
    	b[i.x][i.y+1] = 1;
    	b[i.x+1][i.y+1] = 1;
    }
    bool res = true;
    for(ll i = 0;i<n;i++){
    	for(ll j = 0;j<m;j++){
    		res = res & (a[i][j] == b[i][j]);
    	}
    }
    if(res){
    	cout << mb.size() << endl;
    	for(auto &i : mb){
    		cout << i.x+1 << " " << i.y+1 << endl;
    	}
    }else{
    	cout << -1;
    }
}