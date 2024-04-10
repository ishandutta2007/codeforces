#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 998244353;
const LL INF = 1LL * MX * MX;

int n, m;
int cnt[N];

int height[10];
int dp[10][N];

int sil[N], rv[N];

namespace radek{
#define rep(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define SZ(a) (int)(a).size()
typedef unsigned long long ull;
typedef long long T;//ma byc unsigned int albo ll albo ull
//jak sie przekrecimy przez inta to zly wynik!

const T P = 998244353;
const T ROOT = 1573363368; //root
const int MN=20; // musi by < 26
T omega[1<<MN];


T pw (T x, T n) {
    T res = 1;
    while(n) {
        if (n&1) res = (ull)res*x%P;
        x = (ull)x*x%P;
        n>>=1;
    }
    return res;
}

void fft(vector<T> &a, int n, bool inverse=false) {
    int N = 1<<n;
    a.insert(a.end(), N-SZ(a), 0);
    T root = pw(ROOT, (1<<20)/N*(inverse?(N-1):1));
    omega[0] = 1;
    rep(i, 1, N) omega[i] = (ull)omega[i-1]*root%P;
    rep(i, 0, n) {
        rep(j, 0, 1<<i) {
            rep(k, 0, 1<<(n-i-1)) {
                int s = (j<<(n-i))+k;
                int t = s + (1<<(n-i-1));
                T w = omega[k<<i];
                T temp = a[s] + a[t];
                if (temp >= P) temp -= P;
                T t2 = a[s] - a[t] + P;
                a[t] = (ull) w * t2 % P;
                a[s] = temp;
            }
        }
    }
    rep(i, 0, N) {
        int x=i,y=0;
        rep(j, 0, n)  y=(y<<1)+(x&1), x>>=1;
        if (i<y) swap(a[i],a[y]);
    }
    if (inverse) {
        T inv = pw(N, P-2);
        rep(i, 0, N) a[i] = (ull)a[i]*inv%P;
    }
}
vector<T> conv(vector<T> A, vector<T> B) {
    int n = 31-__builtin_clz(2*(SZ(A)+SZ(B))-1);
    fft(A, n);
    fft(B, n);
    rep(i, 0, (1<<n)) A[i] = (ull) A[i] * B[i] % P;
    fft(A, n, true);
    return A;
}
vector<T> square(vector<T> A) {
    int n = 32-__builtin_clz(2*SZ(A)-1);
    fft(A, n);
    rep(i, 0, (1<<n)) A[i] = (ull) A[i] * A[i] % P;
    fft(A, n, true);
    return A;
}
}

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a) % MX;
		
		b >>= 1;
		a = (1LL * a * a) % MX;
	}
	
	return ret;
}

int newton(int a, int b){
	if(b < 0 || a < b)	return 0;
	return (((1LL * sil[a] * rv[b]) % MX) * rv[a - b]) % MX;
}

void solve(int id, int h){
	int singles = 0, pairs = 0;
	for(int i = 1; i < h; ++i)
		if(cnt[i] == 1)	++singles;
		else if(cnt[i] > 1)	++pairs;
	
	vector <LL> fa(2 * pairs + 1), fb(singles + 1);
	for(int i = 0; i <= 2 * pairs; ++i)
		fa[i] = newton(2 * pairs, i);
	for(int i = 0; i <= singles; ++i)
		fb[i] = (1LL * newton(singles, i) * fast(2, i)) % MX;
	
	auto cur = radek::conv(fa, fb);
	for(int i = 0; i < (int)cur.size(); ++i)
		dp[id][i] = cur[i] % MX;
}

int main(){	
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}

	sil[0] = 1;
	for(int i = 1; i < N; ++i)
		sil[i] = (1LL * sil[i - 1] * i) % MX;
	
	rv[N - 1] = fast(sil[N - 1], MX - 2);
	for(int i = N - 1; i >= 1; --i)
		rv[i - 1] = (1LL * rv[i] * i) % MX;

	for(int i = 1; i <= m; ++i){
		int h;
		scanf("%d", &h);

		height[i] = h + 1;
		solve(i, h);
	}
	
	int q;
	scanf("%d", &q);
	
	while(q--){
		int a;
		scanf("%d", &a);
		a /= 2;

		int ans = 0;
		for(int i = 1; i <= m; ++i)
			if(a >= height[i])
				ans = (ans + dp[i][a - height[i]]) % MX;
		printf("%d\n", ans);
	}
	
	return 0;
}