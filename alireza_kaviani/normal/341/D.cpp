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

const ll MAXN = 1010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , q , fen[5][MAXN][MAXN];

void update(int ind , int x , int y , ll val){
	for(int i = x ; i < MAXN ; i += i & -i){
		for(int j = y ; j < MAXN ; j += j & -j){
			fen[ind][i][j] ^= val;
		}
	}
}

ll get(int ind , int x , int y){
	ll ans = 0;
	for(int i = x ; i ; i -= i & -i){
		for(int j = y ; j ; j -= j & -j){
			ans ^= fen[ind][i][j];
		}
	}
	return ans;
}

void Update(int x , int y , ll val){
	update((x % 2) * 2 + y % 2 , x , y , val);
}

ll Get(int x , int y){
	return get((x % 2) * 2 + y % 2 , x , y);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	while(q--){
		ll type , ax , ay , bx , by , val;
		cin >> type >> ax >> ay >> bx >> by;
//		cout << type << sep << ax << sep << ay << sep << bx << sep << by << endl;
		if(type == 1){
			cout << (Get(ax - 1 , ay - 1) ^ Get(ax - 1 , by) ^ Get(bx , ay - 1) ^ Get(bx , by)) << endl;
		}
		if(type == 2){
			cin >> val;
			Update(ax , ay , val);
			Update(ax , by + 1 , val);
			Update(bx + 1 , ay , val);
			Update(bx + 1 , by + 1 , val);
		}
	}

    return 0;
}
/*

*/