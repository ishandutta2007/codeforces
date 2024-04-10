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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , seg[MAXN << 2];
set<int> st;

void modify(int pos , int val , int id = 1 , int l = 0 , int r = n){
	if(r - l == 1){
		seg[id] = min(seg[id] , val);
		return;
	}
	int mid = l + r >> 1;
	if(pos < mid)	modify(pos , val , lc , l , mid);
	else	modify(pos , val , rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = n){
	if(qr <= l || r <= ql)	return MOD;
	if(ql <= l && r <= qr)	return seg[id];
	int mid = l + r >> 1;
	return min(get(ql , qr , lc , l , mid), get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(seg , seg + MAXN * 4 , MOD);

	cin >> n >> q;
	for(int i = -1 ; i <= n ; i++){
		st.insert(i);
	}
	while(q--){
		int t , l , r , x;
		cin >> t;
		if(t == 0){
			cin >> l >> r >> x;
			l--;
			if(x == 0){
				while(1){
					auto it = st.lower_bound(l);
					if(it == st.end() || (*it) >= r)	break;
					st.erase(it);
				}
			}
			else{
				modify(l , r);
			}
		}
		else{
			cin >> x; x--;
			auto it = st.lower_bound(x);
			if((*it) != x){
				cout << "NO" << endl;
				continue;
			}
			int l = (*prev(it)) , r = (*next(it));
			if(get(l + 1 , x + 1) <= r){
				cout << "YES" << endl;
			}
			else{
				cout << "N/A" << endl;
			}
		}
	}

    return 0;
}
/*

*/