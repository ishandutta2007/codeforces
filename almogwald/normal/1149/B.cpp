#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h> 
#include <iomanip>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
#define forrl(i,a,b,c) for(lol i=a;i<b;i+=c)
#define forrbl(i,a,b,c) for(lol i=a;i>b;i-=c)
#define foril(i,n) forrl(i,0,n,1)
#define foribl(i,n) forrbl(i,n-1,-1,1)
#define fornl(i,n) forrl(i,1,n,1)
#define fornbl(i,n) forrbl(i,n-1,0,1)
#define fortl(i,m,n) forrl(i,m,n,1)
#define fortbl(i,m,n) forrbl(i,n-1,m-1,1)
#define forinl(i,arr) foril(i,arr.size())
#define forinbl(i,arr) foribl(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define deft(t,i) t i; into(i)
#define defl(i) lol i; into(i)
#define defs(i) string i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define out(a) cout << a <<' ';
#define el << endl;
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000007
#define mod %1000000007;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, point> poin;
typedef pair<lol, point> poing;
typedef vector<point> vecp;
#define poi(x,y) make_pair(x,y)
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
lol triangle(lol x) {
	return (((lol)(x + 1))*(x)) / 2;
}
point add(point x, point y) {
	return make_pair(x.first + y.first, x.second + y.second);
}
lol modInverse(lol a)
{
	lol m = maxi;
	lol y = 0, x = 1;
	while (a > 1)
	{
		lol q = a / m;
		lol t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) {
		x += maxi;
	}
	return x;
}
int serch(vecp &x, int num) {
	int l = 0, h = x.size()-1;
	while (l < h) {
		int m = (l + h+1) / 2;
		if (x[m].first < num) {
			h = m-1;
		}
		else {
			l = m;
		}
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	defn defm
		defs(line)
		vector<veci> next(26,veci(n+1));
	fori(i, 26) {
		next[i][n] = n;
		forib(j, n) {
			next[i][j] = next[i][j+1];
			if (line[j] == 'a' + i) {
				next[i][j] = j;
			}
		}
	}
	vector<vector<veci>> dp(1, vector<veci> (1, veci(1)));
	dp[0][0][0] = 0;
	int len1 = 1;
	int len2 = 1;
	int len3 = 1;
	veci f;
	veci s;
	veci t;
	f.push_back(-1);
	s.push_back(-1);
	t.push_back(-1);
	fori(k, m) {
		deft(char, c);
		if (c == '+') {
			defa deft(char, bb);
			int b = bb - 'a';
			if (a == 1) {
				f.push_back(b);
				vector<veci> dummy(len2, veci(len3));
				dp.push_back(dummy);
				dp[len1][0][0] = next[f[len1]][min(n, dp[len1 - 1][0][0])]+1;
				forn(i, len2) {
					dp[len1][i][0] = min(next[f[len1]][min(n, dp[len1 - 1][i][0])] + 1, next[s[i]][min(n, dp[len1][i-1][0])] + 1);
				}
				forn(j, len3) {
					dp[len1][0][j] = min(next[f[len1]][min(n, dp[len1 - 1][0][j])] + 1, next[t[j]][min(n, dp[len1][0][j-1])] + 1);
					forn(i, len2) {
						dp[len1][i][j] = min(next[f[len1]][min(n, dp[len1 - 1][i][j])] + 1, next[s[i]][min(n, dp[len1][i - 1][j])] + 1);
						dp[len1][i][j] = min(dp[len1][i][j], next[t[j]][min(n, dp[len1][i][j - 1])] + 1);
					}
				}
				len1++;
			}
			if (a == 2) {
				s.push_back(b);
				veci dummy(len3);
				fori(i, len1) {
					dp[i].push_back(dummy);
				}
				dp[0][len2][0] = next[s[len2]][min(n, dp[0][len2 - 1][0])] + 1;
				forn(i, len1) {
					dp[i][len2][0] = min(next[s[len2]][min(n, dp[i][len2 - 1][0])] + 1, next[f[i]][min(n, dp[i-1][len2][0])] + 1);
				}
				forn(j, len3) {
					dp[0][len2][j] = min(next[s[len2]][min(n, dp[0][len2 - 1][j])] + 1, next[t[j]][min(n, dp[0][len2][j - 1])] + 1);
					forn(i, len1) {
						dp[i][len2][j] = min(next[s[len2]][min(n, dp[i][len2 - 1][j])] + 1, next[f[i]][min(n, dp[i - 1][len2][j])] + 1);
						dp[i][len2][j] = min(dp[i][len2][j], next[t[j]][min(n, dp[i][len2][j - 1])] + 1);
					}
				}
				len2++;
			}
			if (a == 3) {
				t.push_back(b);
				fori(i, len1) {
					fori(j, len2) {
						dp[i][j].push_back(0);
					}
				}
				dp[0][0][len3] = next[t[len3]][min(n, dp[0][0][len3-1])] + 1;
				forn(i, len1) {
					dp[i][0][len3] = min(next[t[len3]][min(n, dp[i][0][len3 - 1])] + 1, next[f[i]][min(n, dp[i - 1][0][len3])] + 1);
				}
				forn(j, len2) {
					dp[0][j][len3] = min(next[t[len3]][min(n, dp[0][j][len3 - 1])] + 1, next[s[j]][min(n, dp[0][j - 1][len3])] + 1);
					forn(i, len1) {
						dp[i][j][len3] = min(next[t[len3]][min(n, dp[i][j][len3 - 1])] + 1, next[f[i]][min(n, dp[i - 1][j][len3])] + 1);
						dp[i][j][len3] = min(dp[i][j][len3], next[s[j]][min(n, dp[i][j - 1][len3])] + 1);
					}
				}
				len3++;
			}
		}
		else {
			defa;
			if (a == 1) {
				f.pop_back();
				len1--;
				dp.pop_back();
			}
			if (a == 2) {
				s.pop_back();
				len2--;
				fori(i, len1) {
					dp[i].pop_back();
				}
			}
			if (a == 3) {
				t.pop_back();
				len3--;
				fori(i, len1) {
					fori(j, len2) {
						dp[i][j].pop_back();
					}
				}
			}
		}
		if (dp[len1 - 1][len2 - 1][len3 - 1]<= n) {
			co "YES" el
		}
		else {
			co "NO" el
		}
	}
	ex
}