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

ll a[N], b[N], r[N];


void Print(vector<char> X){
	reverse(all(X));
	int cnt = 0;
	for(auto c : X) cnt += (c == 'P');
	if(cnt > 200000){
		cout << "BIG\n" << cnt << '\n';
		exit(0);
	}
	cout << "SMALL\n";
	cout << X.size() << '\n';
	str res = "";
	for(auto c : X) res += c;
	cout << res << '\n';
	exit(0);
}

void Print2(vector<pair<char, ll>> X){
	reverse(all(X));
	ll cnt = 0;
	for(auto c : X) cnt += (c.F == 'P' ? c.S : 0);
	ll sm = 0;
for(auto c : X) sm += c.S;
	if(cnt > 200000){
		cout << "BIG\n" << cnt << '\n';
		exit(0);
	}
	cout << "SMALL\n";
	cout << sm << '\n';
	str res = "";
	for(auto c : X){
		for(int i = 0; i < c.S; i++) res += c.F;
	}
	cout << res << '\n';
	exit(0);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int fl = 1;
	for(int i = 0; i < n; i++) if(a[i] != b[i]) fl = 0;
	if(fl) return cout << "SMALL\n0\n\n", 0;
	fl = 1;
	for(int i = 0; i < n; i++) if(a[i] != b[n - i - 1]) fl = 0;
	if(fl) return cout << "SMALL\n1\nR\n", 0;

	if(n == 1) return cout << "IMPOSSIBLE\n", 0;
	

	for(int i = 0; i < n; i++) r[i] = a[n - 1 - i];
	for(int i = 1; i < n; i++) a[i] += a[i - 1];
	for(int i = 1; i < n; i++) r[i] += r[i - 1];
	

	if(n == 2){
		ll b0 = b[0];
		ll b1 = b[1];
		vector<pair<char, ll>> V;
		while(true){
			if(b[0] == b[1]) break;
			if(b[0] > b[1]){
				swap(b[0], b[1]);
				V.pb({'R', 1});
			} else {
				if(b[0] != a[0]){
					V.pb({'P', b[1] / b[0]});
					b[1] %= b[0];
				} else {
					if(b[1] < a[1]) break;
					if(b[1] > a[1]){
						ll d = (b[1] - a[1]) / b[0];
						b[1] -= b[0] * d;
						V.pb({'P', d});
						if(b[1] != a[1]) break;
						V.pb({'P', 1});
						Print2(V);
					}
				}
			}
			if(*min_element(b, b + 2) <= 0) break;
			int flg = 1;
			for(int i = 0; i < 2; i++) if(a[i] != b[i]) flg = 0;
				if(flg){
					V.pb({'P', 1});
					Print2(V);
				}
		}
		b[0] = b0;
		b[1] = b1;
		V.clear();
		swap(r, a);
		while(true){
			if(b[0] == b[1]) break;
			if(b[0] > b[1]){
				swap(b[0], b[1]);
				V.pb({'R', 1});
			} else {
				if(b[0] != a[0]){
					V.pb({'P', b[1] / b[0]});
					b[1] %= b[0];
				} else {
					if(b[1] < a[1]) break;
					if(b[1] > a[1]){
						ll d = (b[1] - a[1]) / b[0];
						b[1] -= b[0] * d;
						V.pb({'P', d});
						if(b[1] != a[1]) break;
						V.pb({'P', 1});
						V.pb({'R', 1});
						Print2(V);
					}
				}
			}
			if(*min_element(b, b + n) <= 0) break;
			int flg = 1;
			for(int i = 0; i < 2; i++) if(a[i] != b[i]) flg = 0;
			if(flg){
				V.pb({'P', 1});
				V.pb({'R', 1});
				Print2(V);
			}
		}
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int fl2;
	vector<char> C;
	while(true){
		fl = 0;
		fl2 = 0;
		for(int i = 0; i + 1 < n; i++){
			if(b[i] <= b[i + 1]) fl = 1;
			if(b[i] >= b[i + 1]) fl2 = 1;
		}
		if(fl + fl2 == 2){
			return cout << "IMPOSSIBLE\n", 0;
		}
		if(fl){
			for(int i = n - 1; i > 0; i--) b[i] -= b[i - 1];
			C.pb('P');
		} else {
			C.pb('R');
			reverse(b, b + n);
		}
		if(*min_element(b, b + n) <= 0) return cout << "IMPOSSIBLE\n", 0;
		fl = 1;
		for(int i = 0; i < n; i++) if(a[i] != b[i]) fl = 0;
		if(fl){
			C.pb('P');
			Print(C);
		}
		fl = 1;
		for(int i = 0; i < n; i++) if(r[i] != b[i]) fl = 0;
		if(fl){
			C.pb('P');
			C.pb('R');
			Print(C);
		}	
	}
	return 0;
}