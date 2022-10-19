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

const ll MAXN = 320 * 320 + 10;
const ll SQ = 320;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , w , mxB , A[MAXN] , B[MAXN];
ll val[MAXN];
vector<int> vec[MAXN];

struct CHT{
	ll pos = 0 , lz = 0 , L = 0 , R = 0;
	vector<pair<ll , pll>> vec;
	ll insect(pll A , pll B){
		ll x = A.Y - B.Y , y = B.X - A.X;
		return x / y + (x % y > 0);
	}
	void insert(ll a , ll b){
		pll x = {a , b};
		while(SZ(vec) > 0 && vec.back().X >= insect(vec.back().Y , x))	vec.pop_back();
		if(SZ(vec) == 0)	vec.push_back({-INF , x});
		else	vec.push_back({insect(vec.back().Y , x) , x});
	}
	void update(ll r){
//		cout << L << sep << R << endl;
		for(int i = L ; i < R ; i++){
			val[i] += lz + (i <= r);
		}
		vec.clear(); lz = 0 , pos = 0;
		for(int i = L ; i < R ; i++)	insert(i , val[i] * i);
//		if(r == -1)	return;
//		for(pair<ll , pll> i : vec)	cout << i.X << sep << i.Y.X << sep << i.Y.Y << endl;
//		cout << SZ(vec) << endl;
//		assert(SZ(vec) > 0);
	}
	pll get(){
//		assert(SZ(vec) > 0);
		while(pos + 1 < SZ(vec) && vec[pos + 1].X <= lz)	pos++;
//		assert(pos < SZ(vec));
		return {vec[pos].Y.X * lz + vec[pos].Y.Y , vec[pos].Y.X};
	}
} cht[SQ];

void add(int l , int r){
	for(int i = 0 ; i < r / SQ ; i++)	cht[i].lz++;
	cht[r / SQ].update(r);
}

pll get(){
	pll ans = {0 , 0};
	for(int i = 0 ; i < SQ ; i++){
//		if(cht[i].vec.size() == 0)	return cout << cht[i].L << sep << cht[i].R << endl , ans;
		ans = max(ans , cht[i].get());
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> w;
	for(int i = 0 ; i < SQ ; i++){
		cht[i].L = i * SQ; 
		cht[i].R = (i + 1) * SQ;
		cht[i].update(-1);
//		cout << cht[i].vec.size() << endl;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> A[i] >> B[i];
		vec[B[i]].push_back(A[i]);
		mxB = max(mxB , B[i]);
	}
	ll cnt = n;
	for(int i = 0 ; i <= mxB + 1 ; i++){
		pll ans = get();
		cout << ans.X + cnt * w * i << sep << ans.Y << endl;
		for(int j : vec[i])	add(0 , j) , cnt--;
	}

    return 0;
}
/*

*/