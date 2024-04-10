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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll Cross(pll &a, pll &b){
	return a.F * b.S - a.S * b.F;
}
bool CMP(pll a, pll b){
	int fla = a > pll(0, 0);
	int flb = b > pll(0, 0);
	if(fla != flb) return fla < flb;
	return Cross(a, b) < 0;
}

ld len(pll& x){
	return sqrt(x.F*x.F +  x.S * x.S);
}

ll n, k;
pll a[N];

vector<pll> V;
vector<ld> A, B;

void Relax(){
	sort(all(V), [&](pll &a, pll &b){
		return a.F*a.F + a.S*a.S < b.F*b.F + b.S*b.S; 
	});
	int pb = V.size() - 1;
	
	int pf = 0;
	int lw = (k + 1) / 2;
	ld del, ln, smf = 0, smb = 0;
	for(int i = 0; i < min(k, (ll) V.size()); i++){
		del = 0;
		if(i < lw){
			del += len(V[pb]) * (k - 1 - 2 * i);
			smb += len(V[pb]);
			ln = len(V[pb]);
			pb --;
		} else {
			ln = len(V[pf]);
			del += ln * (k - 1 - i);
			del -= (smf + smb);
			
			del += smb - ln*lw;
			del += ln * pf - smf;
			pf ++;
			smf += ln;
		}
		A.pb(del);
		//B.pb(del + ln);
	}
}
int main(){
	scanf("%lld%lld", &n, &k);
	int p = 0;
	ll x, y;
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld", &x, &y);
		if(x == 0 && y == 0) continue;
		a[p ++] = pll(x, y);
	}
	sort(a, a + p, CMP);
	V.pb(a[0]);
	for(int i = 1; i < p; i++){
		if(CMP(a[i], a[i - 1]) == CMP(a[i - 1], a[i])) V.pb(a[i]);
		else {
			Relax();
			V.clear();
			V.pb(a[i]);
		}
	}
	Relax();
	sort(all(A)); reverse(all(A));
	sort(all(B)); reverse(all(B));
	ld ans = 0;

	for(int i = 0; i < min(n - 1, k); i++) ans += A[i];
	ld ans2 = 0;
	for(int i = 0; i < k - 1; i++) ans2 += A[i];
	cout << fixed << setprecision(16) << max(ans,ans2) << '\n';
	return 0;
}