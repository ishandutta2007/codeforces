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

const int Mod = 31607;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int mul(int a, int b){
	return (a * b) % Mod;
}
int bin_pow(int b, int p){
	int res = 1;
	for(int j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
		if(p & j)
			res = mul(res, pw);
	return res;
}


int n;
int iv[N];

int a[25][25];
int pr[25];

const int U = 1 << 23;
int val[U + 10];

int c[25];
const int Z = 1 << 21;
int ml[Z + 3];

int mv[Z];
void Build(){
	ml[0] = 1;
	for(int i = 1; i < 1 << n; i++){
		ml[i] = mul(ml[i ^ (1 << mv[i])], c[mv[i]]);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < Z; i++){
		for(int j = 0; j < 21; j++)
			if(i >> j & 1)
				mv[i] = j;
	}
	for(int i = 0; i < Mod; i++)
		iv[i] = bin_pow(i, Mod - 2);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		pr[i] = 1;
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j] = mul(a[i][j], iv[10000]);
			// debug(a[i][j]);
			pr[i] = mul(pr[i], a[i][j]);
		}
		// debug(pr[i]);
	}
	// debug(a[0][0]);
	int m;
	
	// for(int i = 1; i <= 32; i += i)
		// cerr << "1/" << i << " = " << iv[i] << '\n';
	
	for(int mk = 0; mk < 1 << (n + 2); mk++){
		m = mk;
		// if(mk != 4) continue;
		int d1 = m&1; m /= 2;
		int d2 = m&1; m /= 2;
		val[mk] = 1;
		for(int i = 0; i < n; i++){
			if(m >> i & 1){
				// cerr << "^^^ " << m << ' ' << i << '\n';
				val[mk] = mul(val[mk], pr[i]);
			} else {
				if(d1)
					val[mk] = mul(val[mk], a[i][i]);
				if(d2){
					if((d1) && ((n - 1 - i) == i)) continue;
					val[mk] = mul(val[mk], a[i][n - 1 - i]);
				}
			}
		}
		// cerr << "!! " << d1 << ' ' << d2 << ' ' << m << " : " << val[mk] << '\n'; 
		if(__builtin_popcount(mk) & 1)
			val[mk] = (Mod - val[mk]) % Mod;
	}

	int d1, d2, PP;
	int ALL = (1 << n) - 1;

	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++) c[i] = a[i][j];
		Build();
		for(int mk = 0; mk < 1 << (n + 2); mk++){
			m = mk;
			d1 = m&1; m /= 2;
			d2 = m&1; m /= 2;
			if(d1)
				m |= (1 << j);
			if(d2)
				m |= (1 << (n - 1 - j));
			PP = (ml[ALL ^ m]);
			// debug(PP);
			val[mk] = (val[mk] - mul(val[mk], PP) + Mod) % Mod; 
		}
	}
	ll ans = 0;
	for(int i = 0; i < U; i++) ans = (ans + val[i]) % Mod;
	ans = 1 + Mod - ans;
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}
/*
1
aaaaaaaabbbcc

1
1

*/