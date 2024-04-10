// vaziat meshki-ghermeze !
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
const int N = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

pll operator - (pll A, pll B){
	return pll(A.F - B.F, A.S - B.S);
}

ll Cross(pll A, pll B){
	return A.F * B.S - A.S * B.F;
}

pll A[N], p[N][N];
int n;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll Area;
	cin >> n >> Area;
	Area *= 2;

	for(int i = 0; i < n; i++) cin >> A[i].F >> A[i].S;
	vector<pll> V;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
				p[i][j] = A[j] - A[i], V.pb({i, j});
	sort(all(V), [&](pll i, pll j){
		int fi = p[i.F][i.S] < pll(0, 0);
		int fj = p[j.F][j.S] < pll(0, 0);
		if(fi != fj)
			return fi < fj;
		return Cross(p[i.F][i.S], p[j.F][j.S]) > 0;
	});

	vector<int> I(n), Rv(n);
	iota(all(I), 0);
	sort(all(I), [&](int i, int j){ return A[i] < A[j]; });
	for(int i = 0; i < n; i++) Rv[I[i]] = i;

	for(auto [x, y] : V){
		pll vec = p[x][y];
		int L = -1, R = n, mid;
		while(L + 1 < R){
			mid = (L + R) >> 1;
			if(Cross(vec, A[I[mid]] - A[x]) <= Area) L = mid;
			else R = mid;
		}
		if(L != -1 && Cross(vec, A[I[L]] - A[x]) == Area){
			cout << "Yes\n";
			cout << A[x].F << ' ' << A[x].S << '\n';
			cout << A[y].F << ' ' << A[y].S << '\n';
			cout << A[I[L]].F << ' ' << A[I[L]].S << '\n';
			return 0;
		}
		int px = Rv[x];
		int py = Rv[y];
		// cerr << "!! " << px << ' ' << py << '\n';
		assert(px == py - 1);
		swap(Rv[x], Rv[y]);
		swap(I[px], I[py]);
	}
	cout << "No\n"; 
	return 0;
}