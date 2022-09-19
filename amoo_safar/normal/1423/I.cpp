// I'll Crush you !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

const int SN = (1 << 16);

vector<int> V;
struct Segment {
	int seg[SN << 1];
	void Or(int l, int r, int x, int id = 1, int L = 0, int R = SN){
		if(r <= L || R <= l) return ;
		if(l <= L && R <= r){
			seg[id] |= x;
			return ;
		}
		int mid = (L + R) >> 1;
		Or(l, r, x, id << 1, L, mid);
		Or(l, r, x, id << 1 | 1, mid, R);
	}
	void Get(int l, int r, int id = 1, int L = 0, int R = SN){
		if(r <= L || R <= l) return ;
		if(L + 1 == R){
			V.pb(seg[id]);
			return ;
		}
		int mid = (L + R) >> 1;
		seg[id << 1] |= seg[id];
		seg[id << 1 | 1] |= seg[id];
		Get(l, r, id << 1, L, mid);
		Get(l, r, id << 1 | 1, mid, R);
	}
};
Segment low, hg;

int K, q;
ll lf[N], rf[N], v[N];


struct Segment2 {
	int seg[SN << 1];
	void Or(int idx, int x, int id = 1, int L = 0, int R = SN){
		seg[id] |= x;
		if(L + 1 == R) return ;
		int mid = (L + R) >> 1;
		if(idx < mid)
			Or(idx, x, id << 1, L, mid);
		else
			Or(idx, x, id << 1 | 1, mid, R);
	}
	int Get(int l, int r, int id = 1, int L = 0, int R = SN){
		if(r <= L || R <= l) return 0;
		if(l <= L && R <= r) return seg[id];

		int mid = (L + R) >> 1;
		return Get(l, r, id << 1, L, mid) | Get(l, r, id << 1 | 1, mid, R);
	}
};
Segment2 LSB, MSB;


bool Check(ll lq, ll rq, int vq){
	int ml = lq >> K, llq = lq % (1 << K);
	int mr = rq >> K, lrq = rq % (1 << K);
	int res;
	if(ml == mr){
		res = LSB.Get(llq, lrq + 1) & MSB.Get(ml, ml + 1);
		return (res == vq);
	}
	//////////////
	if(llq != 0){
		res = LSB.Get(llq, 1 << K) & MSB.Get(ml, ml + 1);
		ml ++;
		llq = 0;
		if(res != vq) return false;
	}
	/////////////
	if(ml == mr){
		res = LSB.Get(llq, lrq + 1) & MSB.Get(ml, ml + 1);
		return (res == vq);
	}
	if(lrq != (1<<K) - 1){
		res = LSB.Get(0, lrq + 1) & MSB.Get(mr, mr + 1);
		mr --;
		lrq = (1 << K) - 1;
		if(res != vq) return false;
	}

	res = LSB.Get(0, 1<<K) & MSB.Get(ml, mr + 1);
	return res == vq;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K >> q;
	for(int i = 0; i < q; i++){
		cin >> lf[i] >> rf[i] >> v[i];

		hg.Or(lf[i] >> K, (rf[i] >> K) + 1, v[i]);
		ll ln = rf[i] - lf[i] + 1;
		if(ln >= (1 << K)){
			low.Or(0, 1 << K, v[i]);
		} else {
			int lft = lf[i] & ((1 << K) - 1);
			int rft = lft + ln;
			if(rft > (1 << K))
				rft -= (1 << K);
			if(lft < rft){
				low.Or(lft, rft, v[i]);
			} else {
				low.Or(lft, 1 << K, v[i]);
				low.Or(0, rft, v[i]);
			}
		}
	}

	V.clear();
	low.Get(0, 1<<K);
	vector<int> LW = V;

	V.clear();
	hg.Get(0, 1<<K);
	vector<int> HG = V;
	//////////
	for(int i = 0; i < (1 << K); i++)
		LSB.Or(i, LW[i]);	
	for(int i = 0; i < (1 << K); i++)
		MSB.Or(i, HG[i]);

	/////////	
	for(int i = 0; i < q; i++){
		if(!Check(lf[i], rf[i], v[i]))
			return cout << "impossible\n", 0;
	}
	cout << "possible\n";
	for(auto x : LW) cout << x << '\n';
	for(auto x : HG) cout << x << '\n';
	return 0;
}