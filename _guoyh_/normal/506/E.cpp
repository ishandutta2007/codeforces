# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXS = 205;
const int P = 10007;
int pwri(int x, int y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	int ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int fac[MAXS], ifac[MAXS];
int C(int u, int v){
	if (v < 0 || v > u) return 0;
	else return fac[u] * ifac[v] % P * ifac[u - v] % P;
}
int inv[P];
int len;
char s[MAXS];
int n;
void upd(int &a, int b){
	a = (a + b) % P;
}
void prt(vector<int> p){
	for (int i = 0; i < p.size(); i++) cerr << p[i] << ' ';
	cerr << '\n';
}
vector<int> x_m(int p, int m){  //p*x^m
	vector<int> ans;
	ans.resize(m + 1);
	ans[m] = p;
	return ans;
}
vector<int> add(vector<int> u, vector<int> v){
	// cerr << "add\n";
	// prt(u);
	// prt(v);
	int mxw = max(u.size(), v.size());
	while (mxw <= u.size() && mxw <= v.size() && mxw >= 0 && u[mxw - 1] + v[mxw - 1] == 0) mxw--;
	vector<int> ans;
	ans.resize(mxw);
	for (int i = 0; i < ans.size(); i++){
		if (i < u.size()) ans[i] = (ans[i] + u[i]) % P;
		if (i < v.size()) ans[i] = (ans[i] + v[i]) % P;
	}
	// cerr << "add_finish\n";
	// prt(ans);
	return ans;
}
vector<int> mul(vector<int> u, vector<int> v){
	// cerr << "mul\n";
	// prt(u);
	// prt(v);
	if (u.empty()) return u;
	if (v.empty()) return v;
	vector<int> ans;
	ans.resize(u.size() + v.size() - 1);
	for (int i = 0; i < u.size(); i++){
		for (int j = 0; j < v.size(); j++){
			// assert(i + j < ans.size());
			upd(ans[i + j], u[i] * v[j] % P);
		}
	}
	// cerr << "mul_finish\n";
	// prt(ans);
	return ans;
}
vector<int> mod(vector<int> u, vector<int> v){
	assert(v.size() > 0);
	if (u.size() == 0) return u;
	for (int i = u.size() - 1; i >= v.size() - 1; i--){
		if (u[i]){
			int pd = u[i] * inv[(v[v.size() - 1] + P) % P] % P;
			for (int j = 0; j < v.size(); j++) u[i - int(v.size()) + 1 + j] = (u[i - int(v.size()) + 1 + j] - v[j] * pd % P) % P;
		}
	}
	int mxw = 0;
	for (int i = 0; i < u.size(); i++) if (u[i]) mxw = max(mxw, i + 1);
	vector<int> ans;
	ans.resize(mxw);
	for (int i = 0; i < ans.size(); i++) ans[i] = u[i];
	return ans;
}
vector<int> pwrpm(vector<int> x, int y, vector<int> md){
	// cerr << "pwrpm " << y << '\n';
	// prt(x);
	// prt(md);
	vector<int> ans = x_m(1, 0);
	while (y){
		if (y & 1) ans = mod(mul(ans, x), md);
		x = mod(mul(x, x), md);
		y >>= 1;
		assert(ans.size() <= md.size());
		// cerr << "y " << y << '\n';
		// cerr << "ans\n";
		// prt(ans);
	}
	return ans;
}
vector<int> pwrp(vector<int> x, int y){
	vector<int> ans = x_m(1, 0);
	while (y){
		if (y & 1) ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}
int h[MAXS];
int calc(vector<int> p, vector<int> q, int m){  //[x^m](p(x)/q(x))
	// cerr << "calc " << m << '\n';
	// prt(p);
	// prt(q);
	if (m < 0) return 0;
	for (int i = 0; i <= q.size(); i++){
		h[i] = (i < p.size()) ? p[i] : 0;
		for (int j = max(0, i - int(q.size()) + 1); j < i; j++) h[i] = (h[i] - h[j] * q[i - j] % P) % P;
		h[i] = h[i] * inv[(q[0] + P) % P] % P;
		// cerr << h[i] << ' ';
	}
	// cerr << '\n';
	for (int i = 0; i < int(q.size()) - i - 1; i++) swap(q[i], q[int(q.size()) - i - 1]);
	// int aaa = 0;
	// for (int i = 0; i < q.size(); i++) aaa = (aaa + h[i] * q[i]) % P;
	// assert(aaa == 0);
	vector<int> tmp = x_m(1, 1);
	tmp = pwrpm(tmp, m, q);
	int ans = 0;
	for (int i = 0; i < tmp.size(); i++) ans = (ans + tmp[i] * h[i] % P) % P;
	return ans;
}
int f[MAXS][MAXS][MAXS];
int slv0(){
	f[len + 1][len][0] = 1;
	for (int l = len; l >= 1; l--){
		f[l][l - 1][0] = 1;
		for (int r = l + 1; r <= len; r++){
			for (int i = 0; i <= (r - l + 1) / 2; i++){
				if (s[l] == s[r]) f[l][r][i] = (i > 0) ? f[l + 1][r - 1][i - 1] : 0;
				else f[l][r][i] = (f[l + 1][r][i] + f[l][r - 1][i]) % P;
			}
		}
	}
	// cerr << "ok?\n";
	int ans = 0;
	for (int i = 0; i <= len / 2; i++){
		if (!f[1][len][i]) continue;
		// cerr << "pn " << i << ' ' << f[1][len][i] << '\n';
		int na = i, nb = len - 2 * i;
		vector<int> pn = pwrp(add(x_m(1, 0), x_m(-24, 1)), nb);
		// prt(pn);
		pn = mul(pn, pwrp(add(x_m(1, 0), x_m(-25, 1)), na));
		// prt(pn);
		pn = mul(pn, add(x_m(1, 0), x_m(-26, 1)));
		// prt(pn);
		ans = (ans + f[1][len][i] * calc(x_m(1, 0), pn, (n + len) / 2 - na - nb)) % P;
		// cerr << "ans " << ans << '\n';
	}
	memset(f, 0, sizeof(f));
	for (int l = len; l >= 1; l--){
		f[l][l][0] = 1;
		for (int r = l + 1; r <= len; r++){
			for (int i = 0; i <= (r - l + 1) / 2; i++){
				if (s[l] == s[r]) f[l][r][i] = (i > 0) ? f[l + 1][r - 1][i - 1] : 0;
				else f[l][r][i] = (f[l + 1][r][i] + f[l][r - 1][i]) % P;
			}
		}
	}
	for (int i = 0; i <= len / 2; i++){
		if (!f[1][len][i]) continue;
		int na = i + 1, nb = len - 2 * i - 1;
		vector<int> pn = pwrp(add(x_m(1, 0), x_m(-24, 1)), nb);
		// prt(pn);
		pn = mul(pn, pwrp(add(x_m(1, 0), x_m(-25, 1)), na));
		// prt(pn);
		pn = mul(pn, add(x_m(1, 0), x_m(-26, 1)));
		// prt(pn);
		ans = (ans + f[1][len][i] * calc(x_m(1, 0), pn, (n + len) / 2 - na - nb)) % P;
		// cerr << "ans " << ans << '\n';
	}
	return ans;
}
int slv1(){
	// cerr << "jishu\n";
	n++;
	int ans = slv0();
	memset(f, 0, sizeof(f));
	f[len + 1][len][0] = 1;
	for (int l = len; l >= 1; l--){
		f[l][l - 1][0] = 1;
		for (int r = l + 1; r <= len; r++){
			for (int i = 0; i <= (r - l + 1) / 2; i++){
				if (s[l] == s[r]) f[l][r][i] = (i > 0) ? f[l + 1][r - 1][i - 1] : 0;
				else f[l][r][i] = (f[l + 1][r][i] + f[l][r - 1][i]) % P;
			}
		}
	}
	// cerr << "ok?\n";
	for (int i = 0; i <= len / 2; i++){
		// cerr << "pn " << i << ' ' << f[1][len][i] << '\n';
		vector<int> pn = pwrp(add(x_m(1, 0), x_m(-24, 1)), len - 2 * i);
		// prt(pn);
		pn = mul(pn, pwrp(add(x_m(1, 0), x_m(-25, 1)), i));
		// prt(pn);
		ans = (ans - f[1][len][i] * calc(x_m(1, 0), pn, (n + len) / 2 - i - (len - 2 * i))) % P;
	}
	return ans;
}
int main(){
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < MAXS; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwri(fac[i], -1);
	}
	for (int i = 1; i < P; i++) inv[i] = pwri(i, -1);
	cin >> (s + 1) >> n;
	len = strlen(s + 1);
	if ((n + len) & 1) cout << (slv1() % P + P) % P << '\n';
	else cout << (slv0() % P + P) % P << '\n';
	return 0;
}