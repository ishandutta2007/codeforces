//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, a, b, c, d, ptr, cnt, ord[xn];
string S;
deque <int> dq[xn];

bool cmp(int i, int j){
	return SZ(dq[i]) < SZ(dq[j]);
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> a >> b >> c >> d >> S;
		for (int i = 1; i <= ptr; ++ i)
			dq[i].clear();
		ptr = cnt = 0;
		for (int x : S){
			cnt += x - 'A';
			if (!SZ(dq[ptr]) || dq[ptr].back() == x - 'A')
				ptr ++;
			dq[ptr].push_back(x - 'A');
		}
		if (cnt != b + c + d){
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i <= ptr; ++ i)
			ord[i] = i;
		sort(ord + 1, ord + ptr + 1, cmp);
		for (int ii = 1; ii <= ptr; ++ ii){
			int i = ord[ii];
			while (1 < SZ(dq[i]) && dq[i].front() == 0 && dq[i].back() == 1 && c){
				dq[i].pop_back();
				dq[i].pop_back();
				-- c;
			}
		}
		for (int ii = 1; ii <= ptr; ++ ii){
			int i = ord[ii];
			while (1 < SZ(dq[i]) && dq[i].front() == 1 && dq[i].back() == 0 && d){
				dq[i].pop_back();
				dq[i].pop_back();
				-- d;
			}
		}
		for (int ii = 1; ii <= ptr; ++ ii){
			int i = ord[ii];
			while (1 < SZ(dq[i]) && dq[i].front() == 0 && c){
				dq[i].pop_front();
				dq[i].pop_front();
				-- c;
			}
			while (1 < SZ(dq[i]) && dq[i].front() == 1 && d){
				dq[i].pop_front();
				dq[i].pop_front();
				-- d;
			}
			while (1 < SZ(dq[i]) && dq[i].back() == 1 && c){
				dq[i].pop_back();
				dq[i].pop_back();
				-- c;
			}
			while (1 < SZ(dq[i]) && dq[i].back() == 0 && d){
				dq[i].pop_back();
				dq[i].pop_back();
				-- d;
			}
		}
		for (int ii = 1; ii <= ptr; ++ ii){
			int i = ord[ii];
			if (SZ(dq[i]) && dq[i].back() != 1 && c)
				dq[i].pop_back();
			while (1 < SZ(dq[i]) && dq[i].back() == 1 && c){
				dq[i].pop_back();
				dq[i].pop_back();
				-- c;
			}
		}
		for (int ii = 1; ii <= ptr; ++ ii){
			int i = ord[ii];
			if (SZ(dq[i]) && dq[i].back() != 0 && d)
				dq[i].pop_back();
			while (1 < SZ(dq[i]) && dq[i].back() == 0 && d){
				dq[i].pop_back();
				dq[i].pop_back();
				-- d;
			}
		}
		if (c || d)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}