#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , A , B , q;
set<int> st[2];
set<pii> st2[2];

int insert(int ind , int x){
	auto it = st[ind].lower_bound(x);
	int r = (*it) , l = (*prev(it));
	st[ind].insert(x);
	st2[ind].erase({r - l , l});
	st2[ind].insert({x - l , l});
	st2[ind].insert({r - x , x});
	return (*prev(st2[ind].end())).X;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> q; A = n; B = m;
	st[0].insert(0); st[1].insert(0);
	st[0].insert(n); st[1].insert(m);
	st[0].insert({n , 0}); st[1].insert({m , 0});
	while(q--){
		string type;
		int x;
		cin >> type >> x;
		if(type == "V"){
			A = insert(0 , x);
		}
		else{
			B = insert(1 , x);
		}
		cout << 1ll * A * B << endl;
	}

    return 0;
}
/*

*/