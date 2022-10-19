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
#define lc							id << 1
#define rc							lc | 1

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

struct node{
	int pos = 0;
	vector<pii> vec;
	vector<pair<int , pii>> cht;
	int insect(pii A , pii B){
		int x = A.Y - B.Y , y = B.X - A.X;
		if(y == 0)	return (A.Y <= B.Y ? -MOD : MOD);
		return x / y + (x % y > 0);
	}
	void insert(int a , int b){
		while(SZ(cht) && insect(cht.back().Y , {a , b}) <= cht.back().X)	cht.pop_back();
		if(cht.empty())	cht.push_back({-MOD , {a , b}});
		else	cht.push_back({insect(cht.back().Y , {a , b}) , {a , b}});
	}
	void build(){
		for(pii i : vec)	insert(i.X , i.Y);
	}
	int get(int x){
		while(pos + 1 < SZ(cht) && cht[pos + 1].X <= x)	pos++;
		return cht[pos].Y.X * x + cht[pos].Y.Y;
	}
};

int n , q , A[MAXN] , ps[MAXN] , ans[MAXN];
node seg[MAXN << 2];
vector<pair<pii , pii>> Q;

void build(int id = 1 , int l = 1 , int r = n + 1){
	if(r - l == 1){
		seg[id].vec.push_back({-A[l] , -ps[l] - A[l] * l});
		seg[id].build();
		return;
	}
	int mid = l + r >> 1;
	build(lc , l , mid);
	build(rc , mid , r);
	merge(all(seg[lc].vec) , all(seg[rc].vec) , back_inserter(seg[id].vec));
	seg[id].build();
}

int get(int ql , int qr , int x , int id = 1 , int l = 1 , int r = n + 1){
	if(qr <= l || r <= ql)	return -MOD * 2;
	if(ql <= l && r <= qr)	return seg[id].get(x);
	int mid = l + r >> 1;
	return max(get(ql , qr , x , lc , l , mid) , get(ql , qr , x , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = n ; i >= 1 ; i--)	ps[i] = ps[i + 1] + A[i + 1];
	build();
	cin >> q;
	for(int i = 0 ; i < q ; i++){
		int x , y; cin >> x >> y;
		Q.push_back({{x - y , i} , {x , y}});
	}
	sort(all(Q));
	for(pair<pii , pii> i : Q){
		int ind = i.X.Y , x = i.Y.X , y = i.Y.Y;
		ans[ind] = -get(max(1 , y - x) , y + 1 , x - y) - ps[y];
	}
	for(int i = 0 ; i < q ; i++)	cout << ans[i] << endl;

    return 0;
}
/*

*/