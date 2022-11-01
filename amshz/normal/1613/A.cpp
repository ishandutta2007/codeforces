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

const int xn = - 20 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, x1, y1, x2, y2;
vector <int> vec[2];
bool flag;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> x1 >> y1 >> x2 >> y2;
		vec[0].clear(), vec[1].clear();
		while (x1)
			vec[0].push_back(x1 % 10), x1 /= 10;
		while (x2)
			vec[1].push_back(x2 % 10), x2 /= 10;
		reverse(all(vec[0])), reverse(all(vec[1]));
		if (SZ(vec[0]) + y1 < SZ(vec[1]) + y2)
			cout << "<";
		else if (SZ(vec[0]) + y1 > SZ(vec[1]) + y2)
			cout << ">";
		else{
			flag = false;
			while (SZ(vec[0]) < SZ(vec[1]))
				vec[0].push_back(0);
			while (SZ(vec[1]) < SZ(vec[0]))
				vec[1].push_back(0);
			for (int i = 0; i < min(SZ(vec[0]), SZ(vec[1])); ++ i){
				if (vec[0][i] < vec[1][i]){
					flag = true;
					cout << "<";
					break;
				}
				else if (vec[0][i] > vec[1][i]){
					flag = true;
					cout << ">";
					break;
				}
			}
			if (!flag)
				cout << "=";
		}
		cout << endl;
	}

	return 0;
}