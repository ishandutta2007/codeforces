#include <bits/stdc++.h>

#define ll long long
#define int long long

using namespace std;

const int MAXN = 300000 + 7;
const ll is_query = -(1LL << 62);

struct Line {
    ll m, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double) (z->m - y->m) >= (y->b - z->b) * (long double) (y->m - x->m);
    }

    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};

int q[MAXN], x[MAXN], y[MAXN], ans[MAXN];
const int HINF = LLONG_MIN;

main() {
    //
	ios_base::sync_with_stdio(0);
    HullDynamic cur;
    int n, t, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
       	cin >> q[i];
    	if (q[i] == 1) {
    		cin >> x[i] >> y[i];
    	} else if (q[i] == 2) {
    		cin >> x[i];
    		x[i]--;
    	} else {
    		cin >> x[i];
    	}
    }
    int bl = 4000;
    for (int i = 0; i < n; i++) {
    	ans[i] = HINF;
    }
    for (int i = 0; i < n; i += bl) {
    	HullDynamic block, dead;
    	block.clear(), dead.clear();
    	int end = min(n, i + bl);
    	for (int j = i; j < end; j++) {
    	    if (q[j] == 3) {
    			if (cur.size() != 0) {
    				ans[j] = cur.eval(x[j]);
    			}
    		}
    	}
    	set <int> lol;
    	for (int j = i; j < end; j++) {
    	    if (q[j] == 2 && x[j] < i) {
    	        lol.insert(x[j]);
    	    }
    	}
    	for (int j = i; j < end; j++) {
    	    if (q[j] == 1) {
    	        lol.insert(j);
    	    } else if (q[j] == 2) {
    	        lol.erase(x[j]);
    	    } else {
    	        for (auto p : lol) {
    	            int ind = p;
    	            ans[j] = max(ans[j], x[j] * x[ind] + y[ind]);
    	        }
    	    }
    	}
    	cur.clear();    	
		int nbs = end;
		int nbe = min(n, end + bl);
		set <int> go;
		for (int p = 0; p < nbe; p++) {
			if (q[p] == 2) {
				go.insert(x[p]);
			}
		}
    	for (int j = 0; j < end; j++) {
    		if (q[j] == 1 && !go.count(j)) {
    			cur.insert_line(x[j], y[j]);
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
        if (q[i] == 3) {
            if (ans[i] == HINF) {
                cout << "EMPTY SET" << endl;
            } else {
                cout << ans[i] << endl;
            }
        }
    }
}