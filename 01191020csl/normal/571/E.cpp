#include<bits/stdc++.h>
#define MAXN 1000000000
#define mod 1000000007
using namespace std;
vector<int> prime;
int a[101], b[101];
struct line {
	long long a, b, c;
};
vector<line> mat;
int power(int a, long long n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		n >>= 1;
	}
	return ans;
}
long long gcd(long long x, long long y) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	return y?gcd(y,x%y):x;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= x*(a/b);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		int x = a[i], y = b[i];
		for (int j = 2; j * j <= MAXN; j++)
			if (x % j == 0 || y % j == 0) {
				prime.push_back(j);
				while (x % j == 0) x /= j;
				while (y % j == 0) y /= j;
			}
		if (x > 1) prime.push_back(x);
		if (y > 1) prime.push_back(y);
	}
	sort(prime.begin(), prime.end());
	int l = unique(prime.begin(), prime.end()) - prime.begin();
	vector<long long> a0, b0;
	for (int i = 0; i < l; i++){
		int va = 0, vb = 0;
		while (a[1] % prime[i] == 0) a[1] /= prime[i], ++va;
		while (b[1] % prime[i] == 0) b[1] /= prime[i], ++vb;
		a0.push_back(va), b0.push_back(vb);
	}
	for (int i = 2; i <= n; i++) {
		mat.clear();
		for (int j = 0; j < l; j++) {
			int va = 0, vb = 0;
			while (a[i] % prime[j] == 0) a[i] /= prime[j], ++va;
			while (b[i] % prime[j] == 0) b[i] /= prime[j], ++vb;
			line ins;
			ins.a = b0[j], ins.b = -vb, ins.c = va - a0[j];
			mat.push_back(ins);
		}
		int rnk = 0;
		line base[2];
		for (int j = 0; j < l; j++) {
			if (!rnk && (mat[j].a || mat[j].b)) rnk = 1, base[0] = mat[j];
			if (rnk == 1 && base[0].a*mat[j].b!=base[0].b*mat[j].a) rnk = 2, base[1] = mat[j];
		}
		if (rnk == 0) {
			for (int j = 0; j < l; j++)
				if (mat[j].c != 0) {
					puts("-1");
					return 0;
				}
		}
		if (rnk == 1) {
			long long x, y, tmp = gcd(base[0].a, base[0].b);
			if (base[0].c % tmp != 0) {
				puts("-1");
				return 0;
			}
			if (base[0].c == 0) x = y = 0;
			else {
				base[0].a /= tmp, base[0].b /= tmp, base[0].c /= tmp;
				if (base[0].b == 0) x = base[0].c, y = 0;
				else {
					exgcd(base[0].a, -base[0].b, x, y);
					long long ch = llabs(base[0].b);
					x *= base[0].c;
					x = (x%ch+ch)%ch;
					y = (base[0].c-base[0].a*x)/base[0].b;
					if (y < 0) {
						if (base[0].a == 0) {
							puts("-1");
							return 0;
						}
						ch = llabs(base[0].a);
						y = (y%ch+ch)%ch;
						x = (base[0].c-base[0].b*y)/base[0].a;
						assert(x*base[0].a+base[0].b*y==base[0].c);
					}
				}
			}
			for (int j = 0; j < l; j++) {
				long long ta = b0[j], tb = -mat[j].b;
				if (x*mat[j].a+y*mat[j].b!=mat[j].c) {
					puts("-1");
					return 0;
				}
				a0[j] += x*b0[j], b0[j] = llabs(!ta||!tb?0:(ta/gcd(ta,tb))*tb);
			}
		}
		if (rnk == 2) {
			if (!base[0].b) swap(base[0], base[1]);
			long long t1 = base[0].c*base[1].b-base[1].c*base[0].b, t2 = base[0].a*base[1].b-base[1].a*base[0].b;
			if (t1 % t2 != 0) {
				puts("-1");
				return 0;
			}
			long long x0 = t1 / t2;
			if (x0 < 0) {
				puts("-1");
				return 0;
			}
			t1 = base[0].c-x0*base[0].a, t2 = base[0].b;
			if (t1 % t2 != 0) {
				puts("-1");
				return 0;
			}
			long long y0 = t1 / t2;
			if (y0 < 0) {
				puts("-1");
				return 0;
			}
			for (int j = 0; j < l; j++) {
				if (x0*mat[j].a+y0*mat[j].b!=mat[j].c) {
					puts("-1");
					return 0;
				}
				a0[j] += x0*b0[j], b0[j] = 1;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < l; i++) ans = 1ll*ans*power(prime[i], a0[i]) % mod;
	cout << ans << endl;
}