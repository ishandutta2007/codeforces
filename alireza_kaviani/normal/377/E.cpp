#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 5e10; //998244353; //1e9 + 9;

ll n , s , flag;
vector<pll> vec;
vector<pair<ll , pll>> cht;

ll insect(pll A , pll B){
	ll x = A.Y - B.Y , y = B.X - A.X;
	return x / y + (x % y > 0);
}

void insert(ll a , ll b){
	ll pos = 0;
	while(SZ(cht)){
		pos = insect(cht.back().Y , pll(a , b));
		pos = max(cht.back().X , pos);
		if(pos <= cht.back().X){
			cht.pop_back();
			continue;
		}
		break;
	}
	cht.push_back({pos , {a , b}});
}

pll get(ll x){
	if(x == 0)	return {0 , 0};
	int l = 0 , r = SZ(cht);
	while(r - l > 1){
		int mid = l + r >> 1;
		if(cht[mid].X * cht[mid].Y.X + cht[mid].Y.Y <= x)	l = mid;
		else	r = mid;
	}
	ll diff = x - cht[l].X * cht[l].Y.X - cht[l].Y.Y , pos = cht[l].X + (diff + cht[l].Y.X - 1) / cht[l].Y.X;
	if(r != SZ(cht) && pos >= cht[r].X)	return {cht[r].X * cht[r].Y.X + cht[r].Y.Y , cht[r].X};
	return {pos * cht[l].Y.X + cht[l].Y.Y , pos};
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s;
	for(int i = 0 ; i < n ; i++){
		int v , c;
		cin >> v >> c;
		vec.push_back({v , -c});
	}
	sort(all(vec));
	vector<pll> v;
	for(int i = SZ(vec) - 1 ; i >= 0 ; i--){
		vec[i].Y *= -1;
		if(SZ(v) == 0 || v.back().Y > vec[i].Y){
			v.push_back(vec[i]);
		}
	}
	reverse(all(v)); vec = v;
	for(pll i : vec){
		ll v = i.X , c = i.Y;
		pll A = get(c);
		ll val = A.X , pos = A.Y;
		insert(v , (val - c) - pos * v);
	}
	cout << get(s).Y << endl;

    return 0;
}
/*

*/