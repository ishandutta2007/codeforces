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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

typedef pair<__int128, __int128> frac;
typedef pair<frac, frac> vec;

bool operator > (frac A, frac B){
	return A.F * B.S > A.S * B.F;
}
frac operator -(frac A, frac B){
	return {A.F * B.S - B.F * A.S, A.S * B.S};
}
frac operator *(frac A, frac B){
	return frac(A.F * B.F, A.S * B.S);
}
ostream& operator<<(ostream& os, __int128 X){
	return os << (ll)(X);
}
ostream& operator<<(ostream& os, frac X){
	return os << "(" << X.F << " / " << X.S << ")";
}
ostream& operator<<(ostream& os, vec X){
	return os << "[ " << X.F << " ,  " << X.S << " ]";
}

bool Cross(vec A, vec B){
	return A.F * B.S > A.S * B.F;
}
frac CrossVal(vec A, vec B){
	return A.F * B.S - A.S * B.F;
}
vec operator -(vec A, vec B){
	return vec(A.F - B.F, A.S - B.S);
}

int best[N], imdb[N];
int x[N], y[N];
ld px[N], py[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	pll mx = {-1, -1};
	int id = 1;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		mx = max(mx, pll(x[i], y[i]));
		if(pll(x[i], y[i]) == mx) id = i;
		best[x[i]] = max(best[x[i]], y[i]);
		if(best[x[i]] == y[i]){
			imdb[x[i]] = i;
		}
	}
	vector<vec> H;
	vector<int> Hi;
	H.pb({frac(1, mx.F), frac(1, mx.S)}); Hi.pb(id);
	// cerr << H.back() << '\n';
	// cerr << fixed << setprecision(4);
	int low = mx.S;
	for(int i = mx.F - 1; i > 0; i--){
		if(best[i] == 0) continue;
		if(best[i] <= low) continue;
		low = best[i];
		vec po = {frac(1, i), frac(1, best[i])};
		// cerr << po << '\n';
		while(H.size() > 1 && Cross(po - H[H.size() - 2], H.back() - H[H.size() - 2])){
			// cout << CrossVal(po - H[H.size() - 2], H.back() - H[H.size() - 2]) << '\n';
			H.pop_back(), Hi.pop_back();
		}
		H.pb(po);
		Hi.pb(imdb[i]);
	}

	map<pll, int> mp;
	for(auto i : Hi) mp[pll(x[i], y[i])] = 1;
	for(int i = 0; i < n; i++){
		if(mp[{x[i], y[i]}])
			cout << i + 1 << ' ';
	}
	cout << '\n';
	return 0;
}