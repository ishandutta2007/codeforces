#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, s, l, dp[N];

template <typename T, bool I = true> class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    vector<int> log;
    function<T(const T&, const T&)> f;
 
    SparseTable(): n(), mat(), log(), f() {}
    template <typename U> void build(const U& arr, int _n, function<T(const T&, const T&)> func) {
        n = _n;
        mat.resize((int)log2(n) + 1);
        f = func;
 
        if (I) {
            log.resize(n + 1);
            log[1] = 0;
            for (int i = 2; i <= n; i++) {
                log[i] = 1 + log[i >> 1];
            }
        }
 
        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);
 
        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - j);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    T query(int l, int r) {
        if (I) {
            int j = log[r - l + 1];
            return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
        }
 
        T ans = 0;
        for (int j = mat.size() - 1; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans = f(ans, mat[j][l]);
                l += (1 << j);
            }
        }
        return ans;
    }
};

struct NODE{
	ll ans;
	NODE(): ans(INFi) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.ans = min(a.ans, b.ans);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node].ans = val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve() {
	cin >> n >> s >> l;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = INFi;

	SparseTable<int> mn, mx;
    mn.build(a, n + 1, [&] (int x, int y) { return x < y ? x : y; });
    mx.build(a, n + 1, [&] (int x, int y) { return x > y ? x : y; });

    auto f = [&](int l, int r) -> bool {
    	int mxx = mx.query(l, r), mnn = mn.query(l, r);
    	return mxx - mnn <= s;
    };
    
    build(1, 0, n);
    update(1, 0, n, 0, 0);
    for (int i = l; i <= n; i++) {
    	int left = 1, right = i - l + 1, ans = -1;
    	while (left <= right) {
    		int mid = (left + right) / 2;
    		if (f(mid, i)) {
    			ans = mid;
    			right = mid - 1;
    		} else left = mid + 1;
    	}
    	if (ans != -1) {
    		dp[i] = query(1, 0, n, ans - 1, i - l).ans + 1;
    		update(1, 0, n, i, dp[i]);
    	}
    }
    if (dp[n] > n) deb1(-1)
    else deb1(dp[n])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}