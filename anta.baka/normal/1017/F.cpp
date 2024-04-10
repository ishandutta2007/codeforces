#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;
using uint = unsigned int;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define j1 asdf
#define pb push_back

const int maxn = 1e5, INF = 1e9, CAP = 1e6;
const ll llINF = 1e18;
const ld pi = acos(-1.0), eps = 1e-5;
const int di[] = {0, 0, 1,-1};
const int dj[] = {1,-1, 0, 0};
const int BS = 2e4;

uint n, A, B, C, D, ans;

uint f(uint x) { return A*x*x*x + B*x*x + C*x + D; }
uint g(uint p) {
	uint ret = 0, pp = p;
	while(1) {
		ret += n / pp;
		if((ll)pp * p > n) break;
		pp *= p;
	}
	return ret;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> A >> B >> C >> D;
    bitset<BS> pr;
    pr.set();
    pr[0] = pr[1] = 0;
    for(uint i = 2; i * i <= BS; i++) if(pr[i])
    	for(uint j = i * i; j <= BS; j += i)
    		pr[j] = 0;
    vector<uint> prv(pr.count());
    int tsz = 0;
    for(uint i = 2; i <= BS; i++) if(pr[i]) prv[tsz++] = i;
    for(uint i = 2; i <= BS; i++) if(pr[i]) ans += f(i) * g(i);
    for(uint i = 1; i < (n + BS - 1) / BS; i++) {
    	uint L = i * BS + 1, R = (i + 1) * BS;
    	bitset<BS> foo;
    	foo.set();
    	for(uint x : prv) {
    		for(uint k = (L + x - 1) / x; k * x <= R; k++) foo[k * x - L] = 0;
    	}
    	for(uint i = 0; i < BS; i++) if(foo[i]) ans += f(L + i) * g(L + i);
    }
    cout << ans;
}