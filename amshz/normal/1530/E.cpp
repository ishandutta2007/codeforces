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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, cnt[26];
string S;
vector <int> vec;
bool flag;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> S, n = SZ(S);
		memset(cnt, 0, sizeof cnt);
		for (char c : S)
			++ cnt[c - 'a'];
		flag = false;
		for (int i = 0; i < 26; ++ i)
			if (cnt[i] == n)
				flag = true;
		if (flag){
			cout << S << endl;
			continue;
		}
		for (int i = 0; i < 26; ++ i){
			if (cnt[i] != 1 || flag)
				continue;
			flag = true;
			cout << char('a' + i);
			for (int j = 0; j < 26; ++ j){
				if (i == j)
					continue;
				for (int k = 0; k < cnt[j]; ++ k)
					cout << char('a' + j);
			}
			cout << endl;
		}
		if (flag)
			continue;
		vec.clear();
		for (int i = 0; i < 26; ++ i)
			if (cnt[i])
				vec.push_back(i);
		if (cnt[vec[0]] * 2 - 2 <= n){
			cout << char('a' + vec[0]);
			-- cnt[vec[0]];
			int ptr = 1;
			for (int i = 0; i < cnt[vec[0]]; ++ i){
				cout << char('a' + vec[0]);
				while (ptr < SZ(vec) && !cnt[vec[ptr]])
					++ ptr;
				if (ptr == SZ(vec))
					break;
				cout << char('a' + vec[ptr]);
				-- cnt[vec[ptr]];
			}
			for (int i = vec[0] + 1; i < 26; ++ i)
				for (int j = 0; j < cnt[i]; ++ j)
					cout << char('a' + i);
			cout << endl;
			continue;
		}
		cout << char('a' + vec[0]);
		cout << char('a' + vec[1]);
		-- cnt[vec[0]], -- cnt[vec[1]];
		if (SZ(vec) == 2){
			for (int i = 0; i < cnt[vec[1]]; ++ i)
				cout << char('a' + vec[1]);
			for (int i = 0; i < cnt[vec[0]]; ++ i)
				cout << char('a' + vec[0]);
			cout << endl;
			continue;
		}
		int last = cnt[vec[0]];
		for (int i = 0; i < last; ++ i)
			cout << char('a' + vec[0]), -- cnt[vec[0]];
		cout << char('a' + vec[2]);
		-- cnt[vec[2]];
		for (int i = 0; i < 26; ++ i)
			for (int j = 0; j < cnt[i]; ++ j)
				cout << char('a' + i);
		cout << endl;
	}

	return 0;
}