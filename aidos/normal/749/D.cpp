/*
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
*/
#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define in insert
#define F first
#define S second
#define sz(a) int (a.size ())
#define mp make_pair
#define GGWP return 0
#define all(a) (a).begin(), (a).end()
#define pii pair<int,int>
#define graph vector <vector <int> >
#define fname ""

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;
const int inf = int (1e9);
const double eps = 0.0000000001, pi = 3.14159265358979323;
const int maxn = int (2e5 + 100);
vector <vector <pii> > vec;
pii t[maxn * 4 + 100];
int l[maxn];

inline void build (int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = vec[tl][sz (vec[tl]) - 1];
		return;
	}	
	int tm = (tl + tr) / 2;
	build (v * 2, tl, tm);
	build (v * 2 + 1, tm + 1, tr);
	t[v] = max (t[v * 2], t[v * 2 + 1]);
}

inline void update (int v, int tl, int tr, int pos, int new_val) {           	
	if (tl == tr) {
		t[v].F = new_val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		update (v * 2, tl, tm, pos, new_val);
	else
		update (v * 2 + 1, tm + 1, tr, pos, new_val);
	t[v] = max (t[v * 2], t[v * 2 + 1]);
}

int main () {
	#ifndef  ONLINE_JUDGE
  freopen (fname"in", "r", stdin);
	freopen (fname"out", "w", stdout);
	#endif

	int n;

	scanf ("%d", &n);
	vec.resize (n + 1);

	for (int i=1; i<=n; ++i) {
		int a, b;
		scanf ("%d%d", &a, &b);
		vec[a].pb ({b, a});
	}	

	for (int i=1; i<=n; ++i) {
		if (vec[i].empty())
			vec[i].pb ({-inf, i});
	}

	build (1, 1, n);

	int q;
	scanf ("%d", &q);

	while (q--) {
		int k, key;
		pii res;
		scanf ("%d", &k);
		for (int i=1; i<=k; ++i) {
			scanf ("%d", &l[i]);
			update (1, 1, n, l[i], -inf);
		}
		vector <pii> &mx = vec[t[1].S];
		if (t[1].F == -inf) {
			puts ("0 0");
			goto h;
		}
		update (1, 1, n, mx[0].S, -inf);
		key = t[1].F;
		res = *upper_bound (mx.begin(), mx.end(), make_pair (key, 0));
		update (1, 1, n, mx[0].S, mx[sz (mx) - 1].F);
		printf ("%d %d\n", mx[0].S, res.F);
		h:
		for (int i=1; i<=k; ++i) 
			update (1, 1, n, l[i], vec[l[i]][sz (vec[l[i]]) - 1].F);
	}

	GGWP;
}