#include <cstring>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)10903;
const int maxn = 2e5;
const int inf = (int)1e9;
ll seg[4 * maxn], lazy[4 * maxn], a[maxn];

void change (int id){
    lazy[2 * id + 0] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
    seg[2 * id + 0] += lazy[id];
    seg[2 * id + 1] += lazy[id];
    lazy[id] = 0;
}

ll get (int id, int L, int R, int l, int r){
//    cout << id << " " << L << " " << R << " " << l << " " << r << " " << seg[id] << endl;
    if (L == l and R == r)
        return seg[id];
    int mid = (L + R) / 2;
    ll ret = inf;
    if (lazy[id] != 0)
        change (id);
    if (mid > l)
        ret = min (ret, get (2 * id + 0, L, mid, l, min (mid, r)));
    if (mid < r)
        ret = min (ret, get (2 * id + 1, mid, R, max (l, mid), r));
    return ret;
}

void modifiyer (int id, int L, int R, int l, int r, int val){
//    cout << L << " " << R << " " << l << " " << r << " - " << val << endl;
    if (L == l and R == r){
        lazy[id] += val;
        seg[id] += val;
        return;
    }
    if (lazy[id] != 0)
        change (id);
    int mid = (L + R) / 2;
    if (mid > l)
        modifiyer (2 * id + 0, L, mid, l, min (mid, r), val);
    if (mid < r)
        modifiyer (2 * id + 1, mid ,R, max (l, mid), r, val);
    seg[id] = min (seg[2 * id + 0], seg[2 * id + 1]);
}

void build (int id, int L, int R){
    if (L + 1 == R){
        seg[id] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    build (2 * id + 0, L, mid);
    build (2 * id + 1, mid, R);
    seg[id] = min (seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build (1, 0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
		int l, r;
		char c;
		scanf("%d %d%c", &l, &r, &c);
		r ++;
		if (c == ' '){
			int v;
			cin >> v;
			if (r <= l){
				modifiyer (1, 0, n, l, n, v);
				modifiyer (1, 0, n, 0, r, v);
			}
			else
				modifiyer (1, 0, n, l, r, v);
		}
		else {
			if (r <= l)
				cout << min (get (1, 0, n, l, n), get (1, 0, n, 0, r)) << endl;
			else
				cout << get (1, 0, n, l, r) << endl;
		}
    }
}