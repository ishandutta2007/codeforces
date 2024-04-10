#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>
#include <stack>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
	s << "[";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "]";
	return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
	s << "{";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "}";
	return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

//---------------------------------------------------------------------

const int maxn = 2e5 + 5;
struct tree {
    ll tr[maxn * 4];
    ll ad[maxn * 4];
    int n;

    tree(int n): n(n) {
        build(1, 0, n - 1);
    }

    void build(int v, int l, int r) {
        tr[v] = 0;
        ad[v] = 0;
        if (l != r) {
            int c = (l + r) >> 1;
            build(2 * v, l, c);
            build(2 * v + 1, c + 1, r);
        }
    }

    void add(int v, int l, int r, int i, int j, ll val) {
        if (i <= l && r <= j) {
            ad[v] += val;
            tr[v] += val;
            return;
        }
        int c = (l + r) >> 1;
        if (i <= c) {
            add(2 * v, l, c, i, j, val);
        }
        if (c < j) {
            add(2 * v + 1, c + 1, r, i, j, val);
        }
        tr[v] = ad[v] + min(tr[2 * v], tr[2 * v + 1]);
    }

    void add(int l, int r, ll val) {
        add(1, 0, n - 1, l, r, val);
    }

    ll get(int v, int l, int r, int i, int j) {
        if (i <= l && r <= j) {
            return tr[v];
        }
        ll res = 1e18;
        int c = (l + r) >> 1;
        if (i <= c) {
            chmin(res, get(2 * v, l, c, i, j));
        }
        if (c < j) {
            chmin(res, get(2 * v + 1, c + 1, r, i, j));
        }
        return res + ad[v];
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

const ll INF = 1e18;


tree even(maxn / 2 + 1), odd((maxn + 1) / 2 + 1);

int main() {
	//srand(time(NULL));
	#ifdef LOCAL
		//gen();
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#else
		//freopen("whats.in", "r", stdin);
		//freopen("whats.out", "w", stdout);
	#endif
	//check();
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector < int > b(n, a[0]);
	for (int i = 1; i < n; i++) {
		b[i] = a[i] - b[i-1];
	}
	even.n = n / 2 + 1, odd.n = (n + 1) / 2 + 1;
	
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			odd.add(i/2, i/2, b[i]);
		}
		else {
			even.add(i/2, i/2, b[i]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			if (l & 1) {
				odd.add(l/2, odd.n-1, k);
				if ((r - l + 1) & 1) {
					even.add((r + 1) / 2, even.n - 1, -k);
				}
				else {
					odd.add((r + 1) / 2, odd.n - 1, -k);
				}
			}
			else {
				even.add(l/2, even.n-1, k);
				if ((r - l + 1) & 1) {
					odd.add((r + 1) / 2, even.n - 1, -k);
				}
				else {
					even.add((r + 1) / 2, even.n - 1, -k);
				}
			}
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			ll pref = 0;
			if (l > 0) {
				if ((l - 1) & 1) {
					pref = odd.get((l-1)/2, (l-1)/2);
				}
				else {
					pref = even.get((l-1)/2, (l-1)/2);
				}
			}
			ll oddmin = INF, evenmin = INF;
			if (l == r) {
				if (l & 1) {
					oddmin = odd.get(l/2,r/2);
				}
				else {
					evenmin = even.get(l/2, r/2);
				}
			}
			else {
				if (r & 1) {
					if (l & 1) {
						oddmin = odd.get(l/2, r/2);
						evenmin = even.get((l+1)/2, (r-1)/2);
					}
					else {
						oddmin = odd.get((l+1)/2, r/2);
						evenmin = even.get(l/2, (r-1)/2);
					}
				}
				else {
					if (l & 1) {
						oddmin = odd.get(l/2, (r-1)/2);
						evenmin = even.get((l+1)/2, r/2);
					}
					else {
						oddmin = odd.get((l+1)/2, (r-1)/2);
						evenmin = even.get(l/2, r/2);
					}
				}
			}
			if (l & 1) {
				oddmin += pref;
				evenmin -= pref;
				
				evenmin += 1;
			}
			else {
				oddmin -= pref;
				evenmin += pref;
				
				oddmin += 1;
			}
			if (evenmin <= 0 || oddmin <= 0) {
				printf("0\n");
			}
			else {
				ll last = INF;
				if (r & 1) {
					last = odd.get(r/2, r/2);
					if (l & 1) {
						last += pref;
					}
					else {
						last -= pref;
						last += 1;
					}
				}
				else {
					last = even.get(r/2, r/2);
					if (l & 1) {
						last -= pref;
						last += 1;
					}
					else {
						last += pref;
					}
				}
				if (last == 1) {
					printf("1\n");
				}
				else {
					printf("0\n");
				}
			}
			
		}
	}
	
	return 0;
}