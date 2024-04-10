#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , seg[2][MAXN << 2] , lz[2][MAXN << 2];
vector<int> compress[2];
vector<pair<pii , int>> Q;

int index(int ind , int x){
	int res = lower_bound(all(compress[ind]) , x) - compress[ind].begin();
	return res;
}

void shift(int ind , int id){
	lz[ind][lc] = max(lz[ind][lc] , lz[ind][id]);
	lz[ind][rc] = max(lz[ind][rc] , lz[ind][id]);
	seg[ind][lc] = max(seg[ind][lc] , lz[ind][id]);
	seg[ind][rc] = max(seg[ind][rc] , lz[ind][id]);
	lz[ind][id] = 0;
}

void update(int ind , int ql , int qr , int x , int id = 1 , int l = 0 , int r = q + 1){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		lz[ind][id] = max(lz[ind][id] , x);
		seg[ind][id] = max(seg[ind][id] , x);
		return;
	}
	shift(ind , id);
	int mid = l + r >> 1;
	update(ind , ql , qr , x , lc , l , mid);
	update(ind , ql , qr , x , rc , mid , r);
	seg[ind][id] = max(seg[ind][lc] , seg[ind][rc]);
}

int get(int ind , int x , int id = 1 , int l = 0 , int r = q + 1){
	if(r - l == 1)	return seg[ind][id];
	shift(ind , id);
	int mid = l + r >> 1;
	if(x < mid)	return get(ind , x , lc , l , mid);
	return get(ind , x , rc , mid , r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 0 ; i < q ; i++){
		int x , y;
		string type;
		cin >> x >> y >> type;
		Q.push_back({{x , y} , (type == "L" ? 0 : 1)});
		compress[0].push_back(x);
		compress[1].push_back(y);
	}
	for(int i = 0 ; i < 2 ; i++){
		compress[i].push_back(0);
		sort(all(compress[i]));
		compress[i].resize(unique(all(compress[i])) - compress[i].begin());
	}

	for(pair<pii , int> i : Q){
		int x = i.X.X , y = i.X.Y , t = i.Y;
		if(t == 1)	swap(x , y);
		x = index(t , x);
		y = index(1 - t , y);
		int res = get(1 - t , y);
		update(t , res + 1 , x + 1 , y);
		update(1 - t , y , y + 1 , x);
		cout << compress[t][x] - compress[t][res] << endl;
	}

    return 0;
}
/*

*/